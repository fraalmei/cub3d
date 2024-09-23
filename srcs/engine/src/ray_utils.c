/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:16:16 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/23 11:40:16 by cagonzal         ###   ########.fr       */
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
 * @brief Checks for intersections based on the given angle and steps.
 *
 * This function determines if there is an intersection at a given angle
 * and updates the intersection coordinates and steps accordingly.
 *
 * @param angle The angle at which to check for intersections.
 * @param inter Pointer to the intersection coordinates.
 * @param step Pointer to the step values for the intersection.
 * @param is_horizon Flag indicating if the check is for a horizontal intersection.
 *                   If non-zero, the check is for a horizontal intersection.
 *                   If zero, the check is for a vertical intersection.
 *
 * @return An integer indicating the result of the intersection check.
 */
int	inter_check(float angle, float *inter, float *step, int is_horizon)
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

/**
 * @brief Checks if a wall is hit at the given coordinates.
 *
 * This function determines whether the specified (x, y) coordinates
 * correspond to a wall in the game environment.
 *
 * @param game A pointer to the game structure containing the map and other game data.
 * @param x The x-coordinate to check.
 * @param y The y-coordinate to check.
 *
 * @return An integer indicating whether a wall is hit (1) or not (0).
 */
int	wall_hit(t_game *game, float x, float y)
{
	t_vector2	map_pos;

	if (x < 0 || y < 0)
		return (0);

	map_pos = ft_vector2(floor(x / T_SIZE), floor(y / T_SIZE));
	if (map_pos.y >= game->map->map_size.height || map_pos.x >= game->map->map_size.width)
		return (0);
	if (game->map->map[(int)map_pos.y][(int)map_pos.x] == '1')
		return (1);

	return (0);
}