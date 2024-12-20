/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearcomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:09:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:57:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector4	ft_linear_combv4m4(t_vector4 v, t_matrix4 m)
{
	t_vector4	v1;

	v1.x = v.elements[0] * m.columns[0].x;
	v1.y = v.elements[0] * m.columns[0].y;
	v1.z = v.elements[0] * m.columns[0].z;
	v1.w = v.elements[0] * m.columns[0].w;
	v1.x += v.elements[1] * m.columns[1].x;
	v1.y += v.elements[1] * m.columns[1].y;
	v1.z += v.elements[1] * m.columns[1].z;
	v1.w += v.elements[1] * m.columns[1].w;
	v1.x += v.elements[2] * m.columns[2].x;
	v1.y += v.elements[2] * m.columns[2].y;
	v1.z += v.elements[2] * m.columns[2].z;
	v1.w += v.elements[2] * m.columns[2].w;
	v1.x += v.elements[3] * m.columns[3].x;
	v1.y += v.elements[3] * m.columns[3].y;
	v1.z += v.elements[3] * m.columns[3].z;
	v1.w += v.elements[3] * m.columns[3].w;
	return (v1);
}
