/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:07:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/10/21 15:39:04 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	if (x < 0 || x >= S_WIDTH)
		return ;
	else if (y < 0 || y >= S_HEIGHT)
		return ;
	mlx_put_pixel(game->mlx.img, x, y, color); // put the pixel
}

/**
 * @brief Returns the color of the wall depending on the flag.
 *
 * @param game The game structure.
 * @param flag The flag to determine the color.
 * @return The color of the wall.
 */
mlx_texture_t* get_color(t_game *game, t_ray *ray)
{
	ray->ray_angle = nor_angle(ray->ray_angle); // normalize the angle
	if (ray->side == 0)
	{
		if (ray->ray_angle > M_PI / 2 && ray->ray_angle < 3 * (M_PI / 2))
			return (game->map->map_textures[WEST]->png_img); // west wall
		else
			return (game->map->map_textures[EAST]->png_img); // east wall
	}
	else
	{
		if (ray->ray_angle > 0 && ray->ray_angle < M_PI)
			return (game->map->map_textures[SOUTH]->png_img); // south wall
		else
			return (game->map->map_textures[NORTH]->png_img); // north wall
	}
}

/**
 * @brief Renders a wall segment on the screen.
 *
 * This function is responsible for rendering a segment of the wall on the screen
 * based on the provided raycasting information. It draws the wall from the top
 * pixel (t_pix) to the bottom pixel (b_pix) on the screen.
 *
 * @param game Pointer to the game structure containing game state and settings.
 * @param ray Pointer to the ray structure containing raycasting information.
 * @param t_pix The top pixel coordinate where the wall segment starts.
 * @param b_pix The bottom pixel coordinate where the wall segment ends.
 * @param w_h The height of the wall segment to render.
 */
void render_wall(t_game *game, t_ray *ray, double t_p , double b_p, double w_h)
{
	double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = get_color(game, ray);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / w_h;			
	x_o = get_x_o(ray, texture);
	y_o = (t_p - (S_HEIGHT / 2) + (w_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_p < b_p)
	{
		my_mlx_pixel_put(game, ray->ray, t_p, arr[(int)y_o + (int)x_o]);
		y_o += factor;
		t_p++;
	}
}

/**
 * @brief Renders the floor and ceiling for the given game state.
 *
 * This function is responsible for drawing the floor and ceiling
 * on the screen based on the current game state and raycasting results.
 *
 * @param game Pointer to the game state structure.
 * @param ray Pointer to the ray structure containing raycasting results.
 * @param t_pix The top pixel coordinate for rendering.
 * @param b_pix The bottom pixel coordinate for rendering.
 */
void render_floor_ceiling(t_game *game, t_ray *ray, double t_pix , double b_pix)
{
	int		i;

	i = b_pix;
	while (i < S_HEIGHT)
		my_mlx_pixel_put(game, ray->ray, i++, game->map->map_textures[4]->color); // floor (grass green)
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(game, ray->ray, i++, game->map->map_textures[5]->color); // ceiling (sky blue)
}

void render_scene(t_game *game, t_ray *ray)
{
	double wall_height;
	double b_pix;
	double t_pix;

	ray->dist *= cos(ray->ray_angle - game->player->angle);
	wall_height = (T_SIZE / ray->dist) * ((S_WIDTH / 2) / tan(game->player->fov_rd / 2));
	b_pix = (S_HEIGHT / 2) + (wall_height / 2);
	t_pix = (S_HEIGHT / 2) - (wall_height / 2);
	if (b_pix > S_HEIGHT)
		b_pix = S_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	render_wall(game, ray, t_pix, b_pix, wall_height);
	render_floor_ceiling(game, ray, t_pix, b_pix);
}
