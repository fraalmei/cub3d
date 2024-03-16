/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 20:32:55 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vector4	ft_vector4(double x, double y, double z, double w)
{
	t_vector4	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;

	return (vector);
}

t_vector4	ft_v4add(t_vector4 v1, t_vector4 v2)
{
	t_vector4	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	v.w = v1.w + v2.w;

	return (v);
}

t_vector4	ft_v4subs(t_vector4 v1, t_vector4 v2)
{
	t_vector4	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;

	return (v);
}

t_vector4	ft_v4mult(t_vector4 v1, t_vector4 v2)
{
	t_vector4	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	v.w = v1.w * v2.w;

	return (v);
}

t_vector4	ft_v4fmult(t_vector4 v1, float f)
{
	t_vector4	v;

	v.x = v1.x * f;
	v.y = v1.y * f;
	v.z = v1.z * f;
	v.w = v1.w * f;

	return (v);
}
