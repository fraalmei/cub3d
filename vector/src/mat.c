/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:19:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:58:01 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix2	ft_mat2(void)
{
	t_matrix2	m;

	m.elements[0][0] = 0.0f;
	m.elements[0][1] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 0.0f;
	return (m);
}

t_matrix3	ft_mat3(void)
{
	t_matrix3	m;

	m.elements[0][0] = 0.0f;
	m.elements[0][1] = 0.0f;
	m.elements[0][2] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 0.0f;
	m.elements[1][2] = 0.0f;
	m.elements[2][0] = 0.0f;
	m.elements[2][1] = 0.0f;
	m.elements[2][2] = 0.0f;
	return (m);
}

t_matrix4	ft_mat4(void)
{
	t_matrix4	m;

	m.elements[0][0] = 0.0f;
	m.elements[0][1] = 0.0f;
	m.elements[0][2] = 0.0f;
	m.elements[0][3] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 0.0f;
	m.elements[1][2] = 0.0f;
	m.elements[1][3] = 0.0f;
	m.elements[2][0] = 0.0f;
	m.elements[2][1] = 0.0f;
	m.elements[2][2] = 0.0f;
	m.elements[2][3] = 0.0f;
	m.elements[3][0] = 0.0f;
	m.elements[3][1] = 0.0f;
	m.elements[3][2] = 0.0f;
	m.elements[3][3] = 0.0f;
	return (m);
}
