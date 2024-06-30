/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:07:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/30 09:50:09 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/**
 * @brief Puts the pixel in the image.
 *
 * @param img The image.
 * @param x The x position of the pixel.
 * @param y The y position of the pixel.
 * @param color The color of the pixel.
 */
void my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	if (x < 0 || x >= S_WIDTH || y < 0 || y >= S_HEIGHT)
		return ;
	mlx_pixel_put(game->mlx.p_mlx, game->mlx.window, x, y, color); // put the pixel
}

/**
 * @brief Returns the color of the wall depending on the flag.
 *
 * @param game The game structure.
 * @param flag The flag to determine the color.
 * @return The color of the wall.
 */
int get_color(t_game *game, int flag)
{
	if (flag == 0)
	{
		if (game->ray->ray_angle > M_PI / 2 && game->ray->ray_angle < 3 * (M_PI / 2))
			return (game->west_texture);
		else
			return (game->east_texture);
	}
	else
	{
		if (game->ray->ray_angle > 0 && game->ray->ray_angle < M_PI)
			return (game->south_texture);
		else
			return (game->north_texture);
	}
	return (0);
}

/**
 * @brief Draws the wall of the game screen.
 *
 * @param game The game structure.
 * @param ray The ray number.
 * @param t_pix The top pixel position of the wall.
 * @param b_pix The bottom pixel position of the wall.
 */
void draw_wall(t_game *game, int ray, int t_pix , int b_pix)
{
	int color;

	color = get_color(game, game->ray->flag);
	while (t_pix < b_pix)
		my_mlx_pixel_put(game, ray, t_pix++, color); // Draw the wall
}

/**
 * @brief Renders the floor and ceiling of the game screen.
 *
 * @param game The game structure.
 * @param b_pix The bottom pixel position of the floor.
 * @param t_pix The top pixel position of the ceiling.
 */
void draw_floor_ceiling(t_game *game, int ray, double b_pix, double t_pix)
{
	int i = b_pix;
	while (i < S_HEIGHT)
		my_mlx_pixel_put(game, ray, i++, game->floor_color); // Draw the floor
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(game, ray, i++, game->north_texture); // Draw the ceiling
}

/**
 * @brief Starts the game by drawing the roof and floor of the screen.
 * 
 * @param game The game structure.
 */
void	render_wall(t_game *game, int ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	game->ray->distance = cos(nor_angle(game->ray->ray_angle - game->player.angle));
	wall_h = (T_SIZE / game->ray->distance) * ((S_WIDTH / 2) / tan(FOV_RAD / 2));
	b_pix = S_HEIGHT / 2 + wall_h / 2;
	t_pix = S_HEIGHT / 2 - wall_h / 2;
	if (b_pix < 0)
		b_pix = 0;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(game, ray, t_pix, b_pix);
	draw_floor_ceiling(game, ray, b_pix, t_pix);
}
