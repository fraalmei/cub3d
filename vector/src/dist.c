/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:55:14 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/11 11:02:24 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	dist2(t_vector2 a, t_vector2 b)
{
	return (sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}

double	dist3(t_vector3 a, t_vector3 b)
{
	return (sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)
			+ (b.z - a.z) * (b.z - a.z)));
}

double	dist4(t_vector4 a, t_vector4 b)
{
	return (sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)
			+ (b.z - a.z) * (b.z - a.z) + (b.w - a.w) * (b.w - a.w)));
}
