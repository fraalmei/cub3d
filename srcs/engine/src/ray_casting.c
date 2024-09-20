/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 07:58:21 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/20 15:17:02 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

/**
 * @brief Calculates the horizontal intersection distance for a given ray angle.
 *
 * This function computes the distance from the player's position to the nearest
 * horizontal intersection point of a ray cast at a specified angle. It uses the
 * player's position and the ray angle to determine the intersection point and
 * then calculates the distance to this point.
 *
 * @param game Pointer to the game structure containing the player's position.
 * @param ray_angle The angle of the ray being cast, in radians.
 * @return The distance to the nearest horizontal intersection point, or -1 if
 *         the intersection point is invalid.
 */
double get_v_inter(t_game *game, double ray_angle)
{
	t_vector2	v;
	t_vector2	step;

	v.y = floor(game->player->pos.y / T_SIZE) * T_SIZE;
	if ((ray_angle > 0 && ray_angle < M_PI))
		v.y += T_SIZE;
	v.x = game->player->pos.x + (v.y - game->player->pos.y) / tan(ray_angle);
	step.y = T_SIZE;
	if ((ray_angle > 0 && ray_angle < M_PI) || (ray_angle < -M_PI && ray_angle > -2 * M_PI))
		step.x = -T_SIZE;
	else
		step.x = T_SIZE;
	step.y = T_SIZE * tan(ray_angle);
	if ((ray_angle > M_PI && ray_angle < 2 * M_PI) || (ray_angle < 0 && ray_angle > -M_PI))
		step.y = -T_SIZE * tan(ray_angle);
	while (wall_hit(game, v.x, v.y))
		v = ft_addv2(v, step);
	return (ft_lenv2(ft_subv2(game->player->pos, v)));
}

/**
 * @brief Calculates the vertical intersection distance for a given ray angle.
 *
 * This function computes the distance from the player's position to the nearest
 * vertical intersection point of a ray cast at a specified angle. It uses the
 * player's position and the ray angle to determine the intersection point and
 * then calculates the distance to this point.
 *
 * @param game Pointer to the game structure containing the player's position.
 * @param ray_angle The angle of the ray being cast, in radians.
 * @return The distance to the nearest vertical intersection point, or -1 if
 *         the intersection point is invalid.
 */
double get_h_inter(t_game *game, double ray_angle)
{
	t_vector2	v;
	t_vector2	step;

	v.x = floor(game->player->pos.x / T_SIZE) * T_SIZE;
	if ((ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2))
		v.x += T_SIZE;
	v.y = game->player->pos.y + (v.x - game->player->pos.x) * tan(ray_angle);
	step.x = T_SIZE;
	if ((ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2))
		step.x = -T_SIZE;
	step.y = T_SIZE * tan(ray_angle);
	if ((ray_angle < M_PI / 2 || ray_angle > 3 * M_PI / 2))
		step.y = -T_SIZE * tan(ray_angle);
	while (wall_hit(game, v.x, v.y))
		v = ft_addv2(v, step);
	return (ft_lenv2(ft_subv2(game->player->pos, v)));
	// return (sqrt(pow(v.x - game->player->pos.x, 2) + pow(v.y - game->player->pos.y, 2))); // get the distance
}

/**
 * @brief Renders the scene by calculating and drawing the walls, floor, and ceiling.
 *
 * This function performs the following steps:
 * - Phase 2: Wall rendering
 *   - Calculates the height of the wall based on the distance from the player.
 *   - Determines the top and bottom pixels of the wall to be drawn.
 *   - Draws the wall using the calculated pixel positions.
 * - Phase 3: Floor and ceiling rendering
 *   - Draws the floor and ceiling based on the wall's bottom and top pixel positions.
 *
 * @param game Pointer to the game structure containing game state and ray information.
 * @param ray_i Index of the current ray being processed.
 */
void render_scene(t_game * game, int ray_i)
{
	double	wall_height;
	double	t_pix;
	double	b_pix;
	
	game->ray[ray_i].dist *= cos(
		nor_angle(game->ray[ray_i].ray_angle) - game->player->angle);
	wall_height = (T_SIZE / game->ray[ray_i].dist) * 
				  (S_WIDTH / 2) / tan(FOV_RAD / 2);
	b_pix = (S_HEIGHT / 2) + (wall_height / 2); // get the bottom pixel
	t_pix = (S_HEIGHT / 2) - (wall_height / 2); // get the top pixel
	if (b_pix > S_HEIGHT) // check the bottom pixel
		b_pix = S_HEIGHT;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	render_wall(game, game->ray, t_pix, b_pix);
	render_floor_ceiling(game, game->ray, t_pix, b_pix);
}

/**
 * @brief Casts rays to render the 3D scene.
 *
 * The function performs the following steps:
 * - Phase 1: Cast rays
 * 		- Initialize the ray
 * 		- Calculate the distance to the nearest horizontal wall
 * 		- Calculate the distance to the nearest vertical wall
 * 		- Choose the shortest distance
 * 		- Increment the ray angle
 * 
 * @param game Pointer to the game structure containing the game state.
 */
void cast_rays(t_game *game)
{
	double	ray_angle;
	double	h_inter;
	double	v_inter;
	int		ray_i;
	
	ray_angle = game->player->angle - (FOV_RAD / 2);
	ray_i = -1;
	while (++ray_i < S_WIDTH)
	{
		init_ray(&game->ray[ray_i], ray_i, ray_angle);
		h_inter = get_h_inter(game, nor_angle(game->ray[ray_i].ray_angle));
		v_inter = get_v_inter(game, nor_angle(game->ray[ray_i].ray_angle));
		if (v_inter <= h_inter) // check the distance
			game->ray[ray_i].dist = v_inter; // get the distance
		else
		{
			game->ray[ray_i].dist = h_inter; // get the distance
			game->ray[ray_i].flag = 1; // flag for the wall
		}	
		render_scene(game, ray_i);
		ray_angle += FOV_RAD / S_WIDTH;
	}
}
