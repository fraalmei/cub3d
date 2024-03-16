/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 19:12:18 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector4.h>

t_vector4	ft_v4div(t_vector4 v1, t_vector4 v2)
{
	t_vector4	v;

	v.x = v1.x / v2.x;
	v.y = v1.y / v2.y;
	v.z = v1.z / v2.z;

	return (v);
}


t_vector4	ft_v4fdiv(t_vector4 v1, float f)
{
	t_vector4	v;

	v.x = v1.x / f;
	v.y = v1.y / f;
	v.z = v1.z / f;

	return (v);
}


double	ft_v4mag(t_vector4 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}


double	ft_v4sqrtmag(t_vector4 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}

t_bool	ft_v3eqv(t_vector4 v1, t_vector4 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w);
}
