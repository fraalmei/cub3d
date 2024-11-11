/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 07:58:21 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/11 10:55:40 by fraalmei         ###   ########.fr       */
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
	if (game->map->map[y_m] && x_m < (int)ft_strlen(game->map->map[y_m]))
		if (game->map->map[y_m][x_m] == '1')
			return (0);
	return (1);
}

double	get_h_inter(t_game *game, t_ray *ray, double angl)
{
	t_vector2	h;
	t_vector2	step;
	int			pixel;

	step = ft_vector2(T_SIZE / tan(angl), T_SIZE);
	h.y = floor(game->player->pos.y / T_SIZE) * T_SIZE;
	pixel = inter_check(angl, &h.y, &step.y, 1);
	h.x = game->player->pos.x + (h.y - game->player->pos.y) / tan(angl);
	if ((unit_circle(angl, 'y') && step.x > 0)
		|| (!unit_circle(angl, 'y') && step.x < 0))
		step.x *= -1;
	while (wall_hit(game, h.x, h.y - pixel))
		h = ft_addv2(h, step);
	ray->ray_hor = h;
	return (sqrt(pow(h.x - game->player->pos.x, 2)
			+ pow(h.y - game->player->pos.y, 2)));
}

double	get_v_inter(t_game *game, t_ray *ray, double angl)
{
	t_vector2	v;
	t_vector2	step;
	int			pixel;

	step = ft_vector2(T_SIZE, T_SIZE * tan(angl));
	v.x = floor(game->player->pos.x / T_SIZE) * T_SIZE;
	pixel = inter_check(angl, &v.x, &step.x, 0);
	v.y = game->player->pos.y + (v.x - game->player->pos.x) * tan(angl);
	if ((unit_circle(angl, 'x') && step.y < 0)
		|| (!unit_circle(angl, 'x') && step.y > 0))
		step.y *= -1;
	while (wall_hit(game, v.x - pixel, v.y))
		v = ft_addv2(v, step);
	ray->ray_ver = v;
	return (sqrt(pow(v.x - game->player->pos.x, 2)
			+ pow(v.y - game->player->pos.y, 2)));
}

void	cast_rays(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;
	float	ray_angle;

	ray = -1;
	ray_angle = game->player->angle - (game->player->fov_rd / 2);
	while (++ray < S_WIDTH)
	{
		init_ray(game, ray, ray_angle);
		h_inter = get_h_inter(game, &game->ray[ray],
				nor_angle(game->ray[ray].ray_angle));
		v_inter = get_v_inter(game, &game->ray[ray],
				nor_angle(game->ray[ray].ray_angle));
		if (v_inter <= h_inter)
			game->ray[ray].dist = v_inter;
		else
		{
			game->ray[ray].dist = h_inter;
			game->ray[ray].side = 1;
		}
		render_scene(game, &game->ray[ray]);
		ray_angle += (game->player->fov_rd / S_WIDTH);
	}
}
