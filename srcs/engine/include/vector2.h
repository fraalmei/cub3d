/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:53:58 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 17:19:37 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include <libft.h>

// # define Vector2_Right ft_vector2(1.0f, 0.0f, 0.0f)
// # define Vector2_up ft_vector2(0.0f, 1.0f, 0.0f)
// # define Vector2_left ft_vector2(-1.0f, 0.0f, 0.0f)
// # define Vector2_down ft_vector2(0.0f, -1.0f, 0.0f)

typedef union u_vector2
{
	struct
	{
		double	x;
		double	y;
	};

	struct
	{
		double	u;
		double	v;
	};

	struct
	{
		double	width;
		double	heigth;
	};

	double	elements[2];

}	t_vector2;

typedef union u_matrix2
{
	float		elements[2][2];
	t_vector2	columns[2];
}	t_matrix2;

t_vector2	ft_vector2(double x, double y);
t_vector2	ft_freevector2(double x, double y);
t_vector2	ft_v2add(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2subs(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2mult(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2fmult(t_vector2 v1, float f);
t_vector2	ft_v2div(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2fdiv(t_vector2 v1, float f);
t_vector2	ft_v2mag(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2sqrtmag(t_vector2 v1, t_vector2 v2);
int			ft_v2eqv(t_vector2 v1, t_vector2 v2);

t_matrix2	ft_matrix2(void);
t_matrix2	ft_matr2add(t_matrix2 m1, t_matrix2 m2);
t_matrix2	ft_matr2sub(t_matrix2 m1, t_matrix2 m2);
t_matrix2	ft_matr2mul(t_matrix2 m1, t_matrix2 m2);
t_matrix2	ft_matr2fmul(t_matrix2 m1, float f);
t_matrix2	ft_matr2div(t_matrix2 m1, t_matrix2 m2);
t_matrix2	ft_matr2fdiv(t_matrix2 m1, float f);
int			ft_m2eqv(t_matrix2 v1, t_matrix2 v2);

#endif

