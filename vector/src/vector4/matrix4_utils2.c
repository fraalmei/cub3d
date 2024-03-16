/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 20:23:50 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>


t_matrix4	ft_matr4div(t_matrix4 m1, t_matrix4 m2)
{
	t_matrix4	m;

	m.elements[0][0] = m1.elements[0][0] / m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] / m2.elements[0][1];
	m.elements[1][0] = m1.elements[1][0] / m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] / m2.elements[1][1];

	return (m);
}

t_matrix4	ft_matr4fdiv(t_matrix4 m1, float f)
{
	t_matrix4	m;

	m.elements[0][0] = m1.elements[0][0] / f;
	m.elements[0][1] = m1.elements[0][1] / f;
	m.elements[1][0] = m1.elements[1][0] / f;
	m.elements[1][1] = m1.elements[1][1] / f;

	return (m);
}
