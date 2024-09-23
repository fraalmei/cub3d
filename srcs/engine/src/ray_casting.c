/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 07:58:21 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/23 14:10:58 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void render_scene(t_game *game, t_ray *ray)
{
	int t_pix;
	int b_pix;

	t_pix = (S_HEIGHT / 2) - (S_HEIGHT / ray->dist);
	b_pix = (S_HEIGHT / 2) + (S_HEIGHT / ray->dist);
	if (b_pix > S_HEIGHT)
		b_pix = S_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	render_wall(game, ray, t_pix, b_pix);
	render_floor_ceiling(game, ray, t_pix, b_pix);
}
/**
 * @brief Casts rays to render the 3D scene.
 *
 * The function performs the following steps:
 * - Phase 1: Cast rays
 * 		- Initialize the ray
 * 		- Calculate the distance to the nearest horizontal wall
 * 		- Calculate the distance to the nearest vertical wallc
 * 		- Choose the shortest distance
 * 		- Increment the ray angle
 * 
 * @param game Pointer to the game structure containing the game state.
 */
void cast_rays(t_game *game)
{
	int i;
	double ray_angle;
	t_ray *rays;
	t_vector2 map_pos;

	rays = game->ray;
	map_pos = ft_vector2((int)game->player->pos.x, (int)game->player->pos.y);
	i = -1;
	while (++i < S_WIDTH)
	{
		ray_angle = game->player->angle - (FOV_RAD / 2) + (i * FOV_RAD / S_WIDTH);
		// Phase 1: Initialize ray
		init_ray(&rays[i], i, ray_angle);
		// Phase 2: Calculate distance to the nearest horizontal and vertical walls
		calculate_distances(game, &rays[i], map_pos);
		// Phase 3: Perform DDA
		perform_dda(game, &rays[i], &map_pos);
		// Phase 4: Calculate distance to the wall
		calculate_wall_distance(game, &rays[i], map_pos);
		// Update ray structure
		rays[i].ray_angle = ray_angle;
		render_scene(game, &rays[i]);
	}
}

void calculate_distances(t_game *game, t_ray *ray, t_vector2 map_pos)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (game->player->pos.x - map_pos.x) * 
							ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (map_pos.x + 1.0 - game->player->pos.x) * 
							ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (game->player->pos.y - map_pos.y) * 
							ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (map_pos.y + 1.0 - game->player->pos.y) * 
							ray->delta_dist.y;
	}
}

void perform_dda(t_game *game, t_ray *ray, t_vector2 *map_pos)
{
	int x;
	int y;

	x = (int)map_pos->x / T_SIZE;
	y = (int)map_pos->y / T_SIZE;
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			y += ray->step.y;
			ray->side = 1;
		}
		if (game->map->map[y][x] == '1')
			ray->hit = 1;
	}
}

void calculate_wall_distance(t_game *game, t_ray *ray, t_vector2 map_pos)
{
	if (ray->side == 0)
		ray->dist = (map_pos.x - game->player->pos.x + 
					 (1 - ray->step.x) / 2) / ray->ray_dir.x;
	else
		ray->dist = (map_pos.y - game->player->pos.y + 
					 (1 - ray->step.y) / 2) / ray->ray_dir.y;
}
	// double	ray_angle;
	// double	h_inter;
	// double	v_inter;
	// int		ray_i;
	
	// ray_angle = game->player->angle - (FOV_RAD / 2);
	// ray_i = -1;
	// while (++ray_i < S_WIDTH)
	// {
	// 	init_ray(&game->ray[ray_i], ray_i, ray_angle);
	// 	h_inter = get_h_inter(game, nor_angle(game->ray[ray_i].ray_angle));
	// 	v_inter = get_v_inter(game, nor_angle(game->ray[ray_i].ray_angle));
	// 	if (v_inter <= h_inter) // check the distance
	// 		game->ray[ray_i].dist = v_inter; // get the distance
	// 	else
	// 	{
	// 		game->ray[ray_i].dist = h_inter; // get the distance
	// 		game->ray[ray_i].flag = 1; // flag for the wall
	// 	}	
	// 	render_scene(game, ray_i);
	// 	ray_angle += FOV_RAD / S_WIDTH;
	// }
