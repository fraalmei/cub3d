/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:26:09 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:59:48 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	ft_subv2(t_vector2 v1, t_vector2 v2)
{
	t_vector2	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return (v);
}

t_vector3	ft_subv3(t_vector3 v1, t_vector3 v2)
{
	t_vector3	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vector4	ft_subv4(t_vector4 v1, t_vector4 v2)
{
	t_vector4	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	v.w = v1.w - v2.w;
	return (v);
}
