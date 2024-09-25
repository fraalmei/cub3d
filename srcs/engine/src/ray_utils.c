/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:16:16 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/25 10:51:22 by cagonzal         ###   ########.fr       */
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
