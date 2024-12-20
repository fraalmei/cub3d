/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:53:58 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/11 11:03:26 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>

typedef union u_vector2
{
	struct
	{
		float	x;
		float	y;
	};
	struct
	{
		float	u;
		float	v;
	};
	struct
	{
		float	left;
		float	right;
	};
	struct
	{
		float	width;
		float	height;
	};
	float	elements[2];
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
		float	x;
		float	y;
		float	z;
	};
	struct
	{
		float	u;
		float	v;
		float	w;
	};
	struct
	{
		float	r;
		float	g;
		float	b;
	};
	struct
	{
		float	width;
		float	heigth;
		float	depth;
	};
	float	elements[3];
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
		float	x;
		float	y;
		float	z;
		float	w;
	};
	struct
	{
		float	r;
		float	g;
		float	b;
		float	a;
	};
	float	elements[4];

}	t_vector4;

typedef union u_matrix4
{
	float		elements[4][4];
	t_vector4	columns[4];
}	t_matrix4;

/// creation
t_vector2		ft_vector2(float x, float y);
t_vector3		ft_vector3(float x, float y, float z);
t_vector4		ft_vector4(float x, float y, float z, float w);

t_matrix2		ft_mat2(void);
t_matrix3		ft_mat3(void);
t_matrix4		ft_mat4(void);

t_matrix2		ft_ident2(void);
t_matrix3		ft_ident3(void);
t_matrix4		ft_ident4(void);

// binary
t_vector4		ft_linear_combv4m4(t_vector4 v, t_matrix4 m);

t_vector2		ft_addv2(t_vector2 v1, t_vector2 v2);
t_vector3		ft_addv3(t_vector3 v1, t_vector3 v2);
t_vector4		ft_addv4(t_vector4 v1, t_vector4 v2);

t_matrix2		ft_addm2(t_matrix2 m1, t_matrix2 m2);
t_matrix3		ft_addm3(t_matrix3 m1, t_matrix3 m2);
t_matrix4		ft_addm4(t_matrix4 m1, t_matrix4 m2);

t_vector2		ft_subv2(t_vector2 v1, t_vector2 v2);
t_vector3		ft_subv3(t_vector3 v1, t_vector3 v2);
t_vector4		ft_subv4(t_vector4 v1, t_vector4 v2);

t_matrix2		ft_subm2(t_matrix2 a, t_matrix2 b);
t_matrix3		ft_subm3(t_matrix3 a, t_matrix3 b);
t_matrix4		ft_subm4(t_matrix4 a, t_matrix4 b);

t_vector2		ft_mulv2v(t_vector2 v1, t_vector2 v2);
t_vector3		ft_mulv3v(t_vector3 v1, t_vector3 v2);
t_vector4		ft_mulv4v(t_vector4 v1, t_vector4 v2);

t_vector2		ft_mulm2v(t_matrix2 m, t_vector2 v);
t_vector3		ft_mulm3v(t_matrix3 m, t_vector3 v);
t_vector4		ft_mulm4v(t_matrix4 m, t_vector4 v);

t_matrix2		ft_mulm2m(t_matrix2 m1, t_matrix2 m2);
t_matrix3		ft_mulm3m(t_matrix3 m1, t_matrix3 m2);
t_matrix4		ft_mulm4m(t_matrix4 m1, t_matrix4 m2);

t_vector2		ft_mulv2f(t_vector2 v, float f);
t_vector3		ft_mulv3f(t_vector3 v, float f);
t_vector4		ft_mulv4f(t_vector4 v, float f);

t_matrix2		ft_mulm2f(t_matrix2 m, float f);
t_matrix3		ft_mulm3f(t_matrix3 m, float f);
t_matrix4		ft_mulm4f(t_matrix4 m, float f);

t_vector2		ft_divv2f(t_vector2 v, float f);
t_vector3		ft_divv3f(t_vector3 v, float f);
t_vector4		ft_divv4f(t_vector4 v, float f);

t_matrix2		ft_divm2f(t_matrix2 m, float f);
t_matrix3		ft_divm3f(t_matrix3 m, float f);
t_matrix4		ft_divm4f(t_matrix4 m, float f);

bool			ft_eqv2(t_vector2 v1, t_vector2 v2);
bool			ft_eqv3(t_vector3 v1, t_vector3 v2);
bool			ft_eqv4(t_vector4 v1, t_vector4 v2);

float			ft_dotv2(t_vector2 v1, t_vector2 v2);
float			ft_dotv3(t_vector3 v1, t_vector3 v2);
float			ft_dotv4(t_vector4 v1, t_vector4 v2);

t_vector3		ft_cross(t_vector3 v1, t_vector3 v2);

// unary
float			ft_lensqrv2(t_vector2 v);
float			ft_lensqrv3(t_vector3 v);
float			ft_lensqrv4(t_vector4 v);

float			ft_lenv2(t_vector2 v);
float			ft_lenv3(t_vector3 v);
float			ft_lenv4(t_vector4 v);

float			ft_normv2(t_vector2 v);
float			ft_normv3(t_vector3 v);
float			ft_normv4(t_vector4 v);

double			dist2(t_vector2 a, t_vector2 b);
double			dist3(t_vector3 a, t_vector3 b);
double			dist4(t_vector4 a, t_vector4 b);

t_matrix2		ft_transposem2(t_matrix2 m);
t_matrix3		ft_transposem3(t_matrix3 m);
t_matrix4		ft_transposem4(t_matrix4 m);

// utils
void			printv2(t_vector2 v);
void			printv3(t_vector3 v);
void			printv4(t_vector4 v);

void			printm2(t_matrix2 m);
void			printm3(t_matrix3 m);
void			printm4(t_matrix4 m);

#endif
