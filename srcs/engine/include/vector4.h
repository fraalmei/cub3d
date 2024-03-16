/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:53:58 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 17:21:09 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4_H
# define VECTOR4_H

# include <libft.h>

typedef union u_vector4
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};

	struct
	{
		double	r;
		double	g;
		double	b;
		double	a;
	};

	double	elements[4];

}	t_vector4;

typedef union u_matrix4
{
	float		elements[4][4];
	t_vector4	columns[4];
}	t_matrix4;

t_vector4	ft_vector4(double x, double y, double z, double w);
t_vector4	ft_freevector4(t_vector4 v);
t_vector4	ft_v4add(t_vector4 v1, t_vector4 v2);
t_vector4	ft_v4subs(t_vector4 v1, t_vector4 v2);
t_vector4	ft_v4mult(t_vector4 v1, t_vector4 v2);
t_vector4	ft_v4fmult(t_vector4 v1, float f);
t_vector4	ft_v4div(t_vector4 v1, t_vector4 v2);
t_vector4	ft_v4fdiv(t_vector4 v1, float f);
double		ft_v4mag(t_vector4 v);
double		ft_v4sqrtmag(t_vector4 v);

#endif
