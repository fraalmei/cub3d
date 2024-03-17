/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mulmv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:17:47 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 13:01:05 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	ft_mulm2v(t_matrix2 m, t_vector2 v)
{
	t_vector2	v1;

	v1.x = v.elements[0] * m.columns[0].x;
	v1.y = v.elements[0] * m.columns[0].y;
	v1.x += v.elements[1] * m.columns[1].x;
	v1.y += v.elements[1] * m.columns[1].y;
	return (v1);
}

t_vector3	ft_mulm3v(t_matrix3 m, t_vector3 v)
{
	t_vector3	v1;

	v1.x = v.elements[0] * m.columns[0].x;
	v1.y = v.elements[0] * m.columns[0].y;
	v1.z = v.elements[0] * m.columns[0].z;
	v1.x += v.elements[1] * m.columns[1].x;
	v1.y += v.elements[1] * m.columns[1].y;
	v1.z += v.elements[1] * m.columns[1].z;
	v1.x += v.elements[2] * m.columns[2].x;
	v1.y += v.elements[2] * m.columns[2].y;
	v1.z += v.elements[2] * m.columns[2].z;
	return (v1);
}

t_vector4	ft_mulm4v(t_matrix4 m, t_vector4 v)
{
	return (ft_linear_combv4m4(v, m));
}
