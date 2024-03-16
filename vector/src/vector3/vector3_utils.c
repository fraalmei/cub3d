/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 20:32:00 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vector3	ft_vector3(double x, double y, double z)
{
	t_vector3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;

	return (vector);
}

t_vector3	ft_v3add(t_vector3 v1, t_vector3 v2)
{
	t_vector3	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;

	return (v);
}

t_vector3	ft_v3subs(t_vector3 v1, t_vector3 v2)
{
	t_vector3	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;

	return (v);
}

t_vector3	ft_v3mult(t_vector3 v1, t_vector3 v2)
{
	t_vector3	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;

	return (v);
}

t_vector3	ft_v3fmult(t_vector3 v1, float f)
{
	t_vector3	v;

	v.x = v1.x * f;
	v.y = v1.y * f;
	v.z = v1.z * f;

	return (v);
}
