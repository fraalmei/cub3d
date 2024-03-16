/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 20:01:27 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>


t_matrix3	ft_matrix3(void)
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

t_matrix3	ft_matr3add(t_matrix3 m1, t_matrix3 m2)
{
	t_matrix3	m;

	m.elements[0][0] = m1.elements[0][0] + m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] + m2.elements[0][1];
	m.elements[0][2] = m1.elements[0][2] + m2.elements[0][2];
	m.elements[1][0] = m1.elements[1][0] + m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] + m2.elements[1][1];
	m.elements[1][2] = m1.elements[1][2] + m2.elements[1][2];
	m.elements[2][0] = m1.elements[2][0] + m2.elements[2][0];
	m.elements[2][1] = m1.elements[2][1] + m2.elements[2][1];
	m.elements[2][2] = m1.elements[2][2] + m2.elements[2][2];

	return (m);
}

t_matrix3	ft_matr3sub(t_matrix3 m1, t_matrix3 m2)
{
	t_matrix3	m;

	m.elements[0][0] = m1.elements[0][0] - m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] - m2.elements[0][1];
	m.elements[0][2] = m1.elements[0][2] - m2.elements[0][2];
	m.elements[1][0] = m1.elements[1][0] - m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] - m2.elements[1][1];
	m.elements[1][2] = m1.elements[1][1] - m2.elements[1][2];

	return (m);
}

t_matrix3	ft_matr3mul(t_matrix3 m1, t_matrix3 m2)
{
	t_matrix3	m;

	m.elements[0][0] = m1.elements[0][0] * m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] * m2.elements[0][1];
	m.elements[0][2] = m1.elements[0][2] * m2.elements[0][2];
	m.elements[1][0] = m1.elements[1][0] * m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] * m2.elements[1][1];
	m.elements[1][2] = m1.elements[1][2] * m2.elements[1][2];
	m.elements[2][0] = m1.elements[2][0] * m2.elements[2][0];
	m.elements[2][1] = m1.elements[2][1] * m2.elements[2][1];
	m.elements[2][2] = m1.elements[2][2] * m2.elements[2][2];

	return (m);
}

t_matrix3	ft_matr3fmul(t_matrix3 m1, float f)
{
	t_matrix3	m;

	m.elements[0][0] = m1.elements[0][0] * f;
	m.elements[0][1] = m1.elements[0][1] * f;
	m.elements[0][2] = m1.elements[0][2] * f;
	m.elements[1][0] = m1.elements[1][0] * f;
	m.elements[1][1] = m1.elements[1][1] * f;
	m.elements[1][2] = m1.elements[1][2] * f;
	m.elements[2][0] = m1.elements[2][0] * f;
	m.elements[2][1] = m1.elements[2][1] * f;
	m.elements[2][2] = m1.elements[2][2] * f;

	return (m);
}
