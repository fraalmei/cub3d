/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 19:06:22 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector2.h>


t_matrix2	ft_matr2div(t_matrix2 m1, t_matrix2 m2)
{
	t_matrix2	m;

	m.elements[0][0] = m1.elements[0][0] / m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] / m2.elements[0][1];
	m.elements[1][0] = m1.elements[1][0] / m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] / m2.elements[1][1];

	return (m);
}

t_matrix2	ft_matr2fdiv(t_matrix2 m1, float f)
{
	t_matrix2	m;

	m.elements[0][0] = m1.elements[0][0] / f;
	m.elements[0][1] = m1.elements[0][1] / f;
	m.elements[1][0] = m1.elements[1][0] / f;
	m.elements[1][1] = m1.elements[1][1] / f;

	return (m);
}
