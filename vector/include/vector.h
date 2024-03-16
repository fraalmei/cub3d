/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:53:58 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 20:31:39 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

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

typedef union u_vector3
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};

	struct
	{
		double	u;
		double	v;
		double	w;
	};

	struct
	{
		double	r;
		double	g;
		double	b;
	};

	struct
	{
		double	width;
		double	heigth;
		double	depth;
	};

	double	elements[3];

}	t_vector3;

typedef union u_matrix3
{
	float		elements[3][3];
	t_vector3	columns[3];
}	t_matrix3;

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

// Vector/Matrix 2
t_vector2	ft_vector2(double x, double y);
t_vector2	ft_v2add(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2subs(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2mult(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2fmult(t_vector2 v1, float f);
t_vector2	ft_v2div(t_vector2 v1, t_vector2 v2);
t_vector2	ft_v2fdiv(t_vector2 v1, float f);
double		ft_v2mag(t_vector2 v);
double		ft_v2sqrtmag(t_vector2 v);
int			ft_v2eqv(t_vector2 v1, t_vector2 v2);

t_matrix2	ft_matrix2(void);
t_matrix2	ft_matr2add(t_matrix2 m1, t_matrix2 m2);
t_matrix2	ft_matr2sub(t_matrix2 m1, t_matrix2 m2);
t_matrix2	ft_matr2mul(t_matrix2 m1, t_matrix2 m2);
t_matrix2	ft_matr2fmul(t_matrix2 m1, float f);
t_matrix2	ft_matr2div(t_matrix2 m1, t_matrix2 m2);
t_matrix2	ft_matr2fdiv(t_matrix2 m1, float f);
int			ft_m2eqv(t_matrix2 v1, t_matrix2 v2);

// Vector/Matrix 3
t_vector3	ft_vector3(double x, double y, double z);
t_vector3	ft_v3add(t_vector3 v1, t_vector3 v2);
t_vector3	ft_v3subs(t_vector3 v1, t_vector3 v2);
t_vector3	ft_v3mult(t_vector3 v1, t_vector3 v2);
t_vector3	ft_v3fmult(t_vector3 v1, float f);
t_vector3	ft_v3div(t_vector3 v1, t_vector3 v2);
t_vector3	ft_v3fdiv(t_vector3 v1, float f);
double		ft_v3mag(t_vector3 v);
double		ft_v3sqrtmag(t_vector3 v);
int			ft_v3eqv(t_vector3 v1, t_vector3 v2);

t_matrix3	ft_matrix3(void);
t_matrix3	ft_matr3add(t_matrix3 m1, t_matrix3 m2);
t_matrix3	ft_matr3sub(t_matrix3 m1, t_matrix3 m2);
t_matrix3	ft_matr3mul(t_matrix3 m1, t_matrix3 m2);
t_matrix3	ft_matr3fmul(t_matrix3 m1, float f);
t_matrix3	ft_matr3div(t_matrix3 m1, t_matrix3 m2);
t_matrix3	ft_matr3fdiv(t_matrix3 m1, float f);
int			ft_m3eqv(t_matrix3 v1, t_matrix3 v2);

// Vector/Matrix 4
t_vector4	ft_vector4(double x, double y, double z, double w);
t_vector4	ft_v4add(t_vector4 v1, t_vector4 v2);
t_vector4	ft_v4subs(t_vector4 v1, t_vector4 v2);
t_vector4	ft_v4mult(t_vector4 v1, t_vector4 v2);
t_vector4	ft_v4fmult(t_vector4 v1, float f);
t_vector4	ft_v4div(t_vector4 v1, t_vector4 v2);
t_vector4	ft_v4fdiv(t_vector4 v1, float f);
double		ft_v4mag(t_vector4 v);
double		ft_v4sqrtmag(t_vector4 v);
int			ft_v4eqv(t_vector4 v1, t_vector4 v2);

t_matrix4	ft_matrix4(void);
t_matrix4	ft_matr4add(t_matrix4 m1, t_matrix4 m2);
t_matrix4	ft_matr4sub(t_matrix4 m1, t_matrix4 m2);
t_matrix4	ft_matr4mul(t_matrix4 m1, t_matrix4 m2);
t_matrix4	ft_matr4fmul(t_matrix4 m1, float f);
t_matrix4	ft_matr4div(t_matrix4 m1, t_matrix4 m2);
t_matrix4	ft_matr4fdiv(t_matrix4 m1, float f);
int			ft_m4eqv(t_matrix4 v1, t_matrix4 v2);

#endif

