/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:15:35 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:59:28 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	ft_vector2(float x, float y)
{
	t_vector2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vector3	ft_vector3(float x, float y, float z)
{
	t_vector3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector4	ft_vector4(float x, float y, float z, float w)
{
	t_vector4	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}
