/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 19:59:19 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vector3	ft_v3div(t_vector3 v1, t_vector3 v2)
{
	t_vector3	v;

	v.x = v1.x / v2.x;
	v.y = v1.y / v2.y;
	v.z = v1.z / v2.z;

	return (v);
}


t_vector3	ft_v3fdiv(t_vector3 v1, float f)
{
	t_vector3	v;

	v.x = v1.x / f;
	v.y = v1.y / f;
	v.z = v1.z / f;

	return (v);
}


double	ft_v3mag(t_vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}


double	ft_v3sqrtmag(t_vector3 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

int	ft_v3eqv(t_vector3 v1, t_vector3 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}
