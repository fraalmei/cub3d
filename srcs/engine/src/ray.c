/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 07:58:21 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/29 20:14:57 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * Checks if the intersection point is valid and updates the intersection and step values.
 * 
 * @param angle The angle of the ray.
 * @param inter Pointer to the intersection value.
 * @param step Pointer to the step value.
 * @param is_horizon Flag indicating if the ray is horizontal.
 * @return 1 if the intersection point is valid, -1 otherwise.
 */
int inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
			return (*inter += T_SIZE, -1);
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI && angle < 3 * M_PI / 2))
			return (*inter += T_SIZE, -1);
		*step *= -1;
	}
	return (1);
}

/**
 * Calculates the intersection point with a horizontal wall and returns the distance to it.
 * 
 * @param game Pointer to the game structure.
 * @param angle The angle of the ray.
 * @return The distance to the horizontal wall.
 */
float get_h_inter(t_game *game, double angle)
{
	t_vector2	h;
	t_vector2	step;
	int  		pixel;

	step = ft_vector2(T_SIZE, T_SIZE / tan(angle));
	h.y = floor(game->player.pos.y / T_SIZE) * T_SIZE;
	pixel = inter_check(angle, &h.y, &step.y, 1);
	h.x = game->player.pos.x + (h.y - game->player.pos.y) / tan(angle);
	if ((unit_circle(angle, 'y') && step.x > 0) || (!unit_circle(angle, 'y') && step.x < 0)) // check x_step value
		step.x *= -1;
	while (wall_hit(game, h.x, h.y - pixel)) // check the wall hit whit the pixel value
		h = ft_addv2(h, step);
	return (sqrt(pow(h.x - game->player.pos.x, 2) + pow(h.y - game->player.pos.y, 2)));
}

/**
 * Calculates the intersection point with a vertical wall and returns the distance to it.
 * 
 * @param game Pointer to the game structure.
 * @param angle The angle of the ray.
 * @return The distance to the vertical wall.
 */
float get_v_inter(t_game *game, double angle)
{
	t_vector2	v;
	t_vector2	step;
	int  		pixel;

	step = ft_vector2(T_SIZE, T_SIZE / tan(angle));
	v.x = floor(game->player.pos.x / T_SIZE) * T_SIZE;
	pixel = inter_check(angle, &v.x, &step.x, 0);
	v.y = game->player.pos.y + (v.x - game->player.pos.x) / tan(angle);
	if ((unit_circle(angle, 'y') && step.x > 0) || (!unit_circle(angle, 'y') && step.x < 0)) // check x_step value
		step.x *= -1;
	while (wall_hit(game, v.x, v.y - pixel)) // check the wall hit whit the pixel value
		v = ft_addv2(v, step);
	return (sqrt(pow(v.x - game->player.pos.x, 2) + pow(v.y - game->player.pos.y, 2)));
}

/**
 * Casts rays to render the walls.
 * 
 * @param game Pointer to the game structure.
 */
void cast_rays(t_game *game)
{
	double h_inter;
	double v_inter;
	int ray;

	mlx_clear_window(game->mlx.p_mlx, game->mlx.window);
	ray = 0;
	game->ray->ray_angle = game->player.angle - (game->player.fov_rd / 2);
	while (ray < S_WIDTH)
	{
		game->ray->flag = 0;

		h_inter = get_h_inter(game, nor_angle(game->ray->ray_angle));
		v_inter = get_v_inter(game, nor_angle(game->ray->ray_angle));
		if (v_inter <= h_inter)
			game->ray->distance = v_inter;
		else
		{
			game->ray->distance = h_inter; // get the distance
			game->ray->flag = 1;           // flag for the wall
		}
		render_wall(game, ray);
		ray++;
		game->ray->ray_angle += (game->player.fov_rd / S_WIDTH);
	}
}