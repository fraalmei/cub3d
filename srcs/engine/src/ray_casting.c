/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 07:58:21 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/30 11:42:56 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	inter_check(double angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += T_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += T_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(t_game *game, double x, double y)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor(x / T_SIZE);
	y_m = floor(y / T_SIZE);
	if (y_m >= game->map->map_size.height || x_m >= game->map->map_size.width)
		return (0);
	if (game->map->map[y_m] && x_m <= (int)strlen(game->map->map[y_m]))
		if (game->map->map[y_m][x_m] == '1')
			return (0);
	return (1);
}

double	get_h_inter(t_game *game, double angl)
{
	t_vector2	h;
	t_vector2	step;
	int			pixel;

	step = ft_vector2(T_SIZE / tan(angl), T_SIZE);
	h.y = floor(game->player->pos.y / T_SIZE) * T_SIZE;
	pixel = inter_check(angl, &h.y, &step.y, 1);
	h.x = game->player->pos.x + (h.y - game->player->pos.y) / tan(angl);
	if ((unit_circle(angl, 'y') && step.x > 0) || (!unit_circle(angl, 'y') && step.x < 0)) // check x_step value
		step.x *= -1;
	while (wall_hit(game, h.x, h.y - pixel))
		h = ft_addv2(h, step);
	// PRINT_DEBUG("Function %s: Step H Stop\n", __func__);
	return (sqrt(pow(h.x - game->player->pos.x, 2) + pow(h.y - game->player->pos.y, 2)));
	// return (ft_lenv2(ft_subv2(h, game->player->pos)));
}

double	get_v_inter(t_game *game, double angl)
{
	t_vector2	v;
	t_vector2	step;
	int			pixel;

	step = ft_vector2(T_SIZE, T_SIZE * tan(angl));
	v.x = floor(game->player->pos.x / T_SIZE) * T_SIZE;
	pixel = inter_check(angl, &v.x, &step.x, 0); // check the intersection and get the pixel value
	v.y = game->player->pos.y + (v.x - game->player->pos.x) * tan(angl);
	if ((unit_circle(angl, 'x') && step.y < 0) || (!unit_circle(angl, 'x') && step.y > 0)) // check y_step value
		step.y *= -1;
	while (wall_hit(game, v.x - pixel, v.y))
		v = ft_addv2(v, step);
	// PRINT_DEBUG("Function %s: Step V Stop\n", __func__);
	return (sqrt(pow(v.x - game->player->pos.x, 2) + pow(v.y - game->player->pos.y, 2)));
	// return (ft_lenv2(ft_subv2(v, game->player->pos)));
}

void	cast_rays(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;
	float	ray_angle;

	ray = -1;
	ray_angle = game->player->angle - (game->player->fov_rd / 2); // start angle
	PRINT_DEBUG("Function %s: Ray_n %d\n", __func__, game->n_ray);
	while (++ray < game->n_ray) // S_WIDTH)
	{
		game->ray[ray].side = 0;
		game->ray[ray].ray = ray;
		game->ray[ray].ray_angle = ray_angle;
		// PRINT_DEBUG("Function %s: Ray %d\n", __func__, ray);
		h_inter = get_h_inter(game, nor_angle(game->ray[ray].ray_angle));
		v_inter = get_v_inter(game, nor_angle(game->ray[ray].ray_angle));
		if (v_inter <= h_inter)
			game->ray[ray].dist = v_inter;
		else
		{
			game->ray[ray].dist = h_inter;
			game->ray[ray].side = 1;
		}
		render_scene(game, &game->ray[ray]);
		ray_angle += (game->player->fov_rd / S_WIDTH); // next angle
	}
}
