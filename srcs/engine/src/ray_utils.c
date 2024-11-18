/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:16:16 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/11 10:57:14 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/**
 * @brief Normalizes the given angle between 0 and 2*pi.
 * If the angle is negative, it is converted to a positive angle.
 *
 * @param angle The angle to be normalized.
 * @return The normalized angle between 0 and 2*pi.
 */

float	nor_angle(float angle)	// normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

/**
 * Checks if the given angle lies within the unit circle quadrant.
 * 
 * @param angle The angle in radians.
 * @param c The character representing the axis ('x' or 'y').
 * @return 1 if the angle lies within the specified quadrant, 0 otherwise.
 */
int	unit_circle(float angle, char c)
{
	if (c == 'x')
		if (angle > 0 && angle < M_PI)
			return (1);
	if (c == 'y')
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	return (0);
}

/** 
 * @brief Returns the x coordinate of the texture to be rendered.
 * 
 * @param game Pointer to the game structure.
 * @param ray Pointer to the ray structure containing raycasting information.
 * @param texture Pointer to the texture structure.
*/
double	get_x_o(t_game *game, t_ray *ray, mlx_texture_t *texture)
{
	double	x_o;

	(void)game;
	if (ray->side == 1)
		x_o = fmodf((ray->ray_hor.x
					* (texture->width / T_SIZE)), texture->width);
	else
		x_o = fmodf((ray->ray_ver.y
					* (texture->width / T_SIZE)), texture->width);
	return (x_o);
}

/**
 * @brief Reverses the bytes of an integer.
 * 			- The function takes an integer as input
 * 			and returns the integer with the bytes reversed.
 *	
 * @param c The integer to reverse the bytes of.
 * @return The integer with the bytes reversed.
 */
int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

void	init_ray(t_game *game, int ray, float ray_angle)
{
	game->ray[ray].side = 0;
	game->ray[ray].ray = ray;
	game->ray[ray].ray_angle = ray_angle;
}
