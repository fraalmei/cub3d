/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:35:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:56:45 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	ft_lenv2(t_vector2 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y));
}

float	ft_lenv3(t_vector3 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

float	ft_lenv4(t_vector4 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}
