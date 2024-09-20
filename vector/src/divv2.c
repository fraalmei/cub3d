/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:56:42 by pedromar          #+#    #+#             */
/*   Updated: 2024/09/20 12:29:59 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	ft_divv2f(t_vector2 v, float f)
{
	t_vector2	v1;

	v1.x = v.x / f;
	v1.y = v.y / f;
	return (v1);
}

t_vector3	ft_divv3f(t_vector3 v, float f)
{
	t_vector3	v1;

	v1.x = v.x / f;
	v1.y = v.y / f;
	v1.z = v.z / f;
	return (v1);
}

t_vector4	ft_divv4f(t_vector4 v, float f)
{
	t_vector4	v1;

	v1.x = v.x / f;
	v1.y = v.y / f;
	v1.z = v.z / f;
	v1.w = v.w / f;
	return (v1);
}
