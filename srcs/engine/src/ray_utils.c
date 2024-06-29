/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:16:16 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/29 20:15:00 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Normalizes the given angle between 0 and 2*pi.
 * If the angle is negative, it is converted to a positive angle.
 *
 * @param angle The angle to be normalized.
 * @return The normalized angle between 0 and 2*pi.
 */
float nor_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI); // normalize angle between 0 and 2*pi
	if (angle < 0)
		angle += 2 * M_PI; // ensure positive angle
	return (angle);
}

/**
 * Checks if the given angle lies within the unit circle quadrant.
 * 
 * @param angle The angle in radians.
 * @param c The character representing the axis ('x' or 'y').
 * @return 1 if the angle lies within the specified quadrant, 0 otherwise.
 */
int unit_circle(float angle, char c)
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
 * Checks if a wall is hit by the casted ray.
 *
 * @param game Pointer to the game structure.
 * @param x The x-coordinate of the point to check.
 * @param y The y-coordinate of the point to check.
 * @return 1 if a wall is hit, 0 otherwise.
 */
int wall_hit(t_game *game, float x, float y)
{
	t_vector2  m;

	if (x < 0 || y < 0)
		return (0);
	m = ft_vector2(floor(x / T_SIZE), floor(y / T_SIZE)); // get the y position in the map
	if ((m.y >= game->map_size.height || m.x >= game->map_size.width))
		return (0);
	if (game->matrix[(int)m.y] && m.x <= (int)ft_strlen(game->matrix[(int)m.y]))
	{
		if (game->matrix[(int)m.y][(int)m.x] == '1')
			return (0);
	}
	return (1);
}