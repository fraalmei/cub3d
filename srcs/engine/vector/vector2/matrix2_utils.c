/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/15 11:59:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector2.h>


t_matrix2   ft_matrix2(void)
{
    t_matrix2 m;

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

t_matrix2   ft_matr3add(t_matrix2 m1, t_matrix2 m2)
{
    t_matrix2 m;

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

t_matrix2   ft_matr3sub(t_matrix2 m1, t_matrix2 m2)
{
    t_matrix2 m;

    m.elements[0][0] = m1.elements[0][0] - m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] - m2.elements[0][1];
	m.elements[0][2] = m1.elements[0][2] - m2.elements[0][2];
	m.elements[1][0] = m1.elements[1][0] - m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] - m2.elements[1][1];
	m.elements[1][2] = m1.elements[1][1] - m2.elements[1][2];
    
	return (m);
}

t_matrix2   ft_matr3mul(t_matrix2 m1, t_matrix2 m2)
{
    t_matrix2 m;

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

t_matrix2   ft_matr3fmul(t_matrix2 m1, float f)
{
    t_matrix2 m;

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


t_matrix2   ft_matr3div(t_matrix2 m1, t_matrix2 m2)
{
    t_matrix2 m;

    m.elements[0][0] = m1.elements[0][0] / m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] / m2.elements[0][1];
	m.elements[0][2] = m1.elements[0][2] / m2.elements[0][2];
	m.elements[1][0] = m1.elements[1][0] / m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] / m2.elements[1][1];
	m.elements[1][2] = m1.elements[1][2] / m2.elements[1][2];
	m.elements[2][0] = m1.elements[2][0] / m2.elements[2][0];
	m.elements[2][1] = m1.elements[2][1] / m2.elements[2][1];
	m.elements[2][2] = m1.elements[2][2] / m2.elements[2][2];
    
	return (m);
}

t_matrix2   ft_matr3fdiv(t_matrix2 m1, float f)
{
    t_matrix2 m;

    m.elements[0][0] = m1.elements[0][0] / f;
	m.elements[0][1] = m1.elements[0][1] / f;
	m.elements[0][2] = m1.elements[0][2] / f;
	m.elements[1][0] = m1.elements[1][0] / f;
	m.elements[1][1] = m1.elements[1][1] / f;
	m.elements[1][2] = m1.elements[1][2] / f;
	m.elements[2][0] = m1.elements[2][0] / f;
	m.elements[2][1] = m1.elements[2][1] / f;
	m.elements[2][2] = m1.elements[2][2] / f;
    
	return (m);
}