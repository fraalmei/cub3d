/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:07:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/23 14:12:50 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	if (x < 0 || y < 0)
		return ;
	else if (x >= S_WIDTH || y >= S_HEIGHT)
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
int get_color(t_game *game, t_ray *ray)
{
	(void)game;
	ray->ray_angle = nor_angle(ray->ray_angle); // normalize the angle
	if (ray->hit == 0)
	{
		if (ray->ray_angle > M_PI / 2 && ray->ray_angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF); // west wall (gray)
		else
			return (0xB5B5B5FF); // east wall (gray)
	}
	else
	{
		if (ray->ray_angle > 0 && ray->ray_angle < M_PI)
			return (0xF5F5F5FF); // south wall (white)
		else
			return (0xF5F5F5FF); // north wall (white)
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
 */
void render_wall(t_game *game, t_ray *ray, int t_pix , int b_pix)
{
	int color;

	color = get_color(game, ray);
	while (t_pix < b_pix)
		my_mlx_pixel_put(game, ray->ray, t_pix++, color);
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
void render_floor_ceiling(t_game *game, t_ray *ray, int t_pix , int b_pix)
{
	int		i;

	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(game, ray->ray, i++, game->roof_color); // ceiling
	i = b_pix;
	while (i < S_HEIGHT)
		my_mlx_pixel_put(game, ray->ray, i++, game->floor_color); // floor
}
