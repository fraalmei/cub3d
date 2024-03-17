/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mulvf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:39:15 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 13:00:37 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	ft_mulv2f(t_vector2 v, float f)
{
	t_vector2	v1;

	v1.x = v.x * f;
	v1.y = v.y * f;
	return (v1);
}

t_vector3	ft_mulv3f(t_vector3 v, float f)
{
	t_vector3	v1;

	v1.x = v.x * f;
	v1.y = v.y * f;
	v1.z = v.z * f;
	return (v1);
}

t_vector4	ft_mulv4f(t_vector4 v, float f)
{
	t_vector4	v1;

	v1.x = v.x * f;
	v1.y = v.y * f;
	v1.z = v.z * f;
	v1.w = v.w * f;
	return (v1);
}
