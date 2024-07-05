/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:05:17 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/05 12:05:17 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>

typedef union u_vector2
{
	struct // 2D Coords
	{
		double	x;
		double	y;
	};
	struct // Normalized coords
	{
		double	u;
		double	v;
	};
	struct // Color
	{
		double	r;
		double	g;
	};
	double	elements[2]; // Generic Array
}	t_vector2;

typedef union u_vector3
{
	struct // 3D Coords
	{
		double	x;
		double	y;
		double	z;
	};
	struct // Normalized coords
	{
		double	u;
		double	v;
		double	w;
	};
	struct // Color
	{
		double	r;
		double	g;
		double	b;
	};
	double	elements[3]; // Generic Array
}	t_vector3;

typedef union u_vector4
{
	struct // 4D Coords
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	struct // Color
	{
		double	r;
		double	g;
		double	b;
		double	a;
	};
	double	elements[4]; // Generic Array
}	t_vector4;

typedef union u_matrix3
{
	float		elements[3][3];
	t_vector3	columns[3];
}	t_matrix3;

t_vector2	ft_vector2(double x, double y);
t_vector2	ft_vector2_add(t_vector2 v1, t_vector2 v2);
t_vector2	ft_vector2_subs(t_vector2 v1, t_vector2 v2);
t_vector2	ft_vector2_mult(t_vector2 v1, t_vector2 v2);
t_vector2	ft_vector2_div(t_vector2 v1, t_vector2 v2);
t_vector2	ft_vector2_fmult(t_vector2 v1, float single);
t_vector2	ft_vector2_fdiv(t_vector2 v1, float single);

t_vector3	ft_vector3(double x, double y, double z);
t_vector3	ft_vector3_add(t_vector3 v1, t_vector3 v2);
t_vector3	ft_vector3_subs(t_vector3 v1, t_vector3 v2);
t_vector3	ft_vector3_mult(t_vector3 v1, t_vector3 v2);
t_vector3	ft_vector3_div(t_vector3 v1, t_vector3 v2);
t_vector3	ft_vector3_fmult(t_vector3 v1, float single);
t_vector3	ft_vector3_fdiv(t_vector3 v1, float single);

t_vector4	ft_vector4(double x, double y, double z, double w);
t_vector4	ft_vector4_add(t_vector4 v1, t_vector4 v2);
t_vector4	ft_vector4_subs(t_vector4 v1, t_vector4 v2);
t_vector4	ft_vector4_mult(t_vector4 v1, t_vector4 v2);
t_vector4	ft_vector4_div(t_vector4 v1, t_vector4 v2);
t_vector4	ft_vector4_fmult(t_vector4 v1, float single);
t_vector4	ft_vector4_fdiv(t_vector4 v1, float single);

void		printVector2(t_vector2 v);
void		printVector3(t_vector3 v);
void		printVector4(t_vector4 v);

double		ft_vector2_magn(t_vector2 pVec);
double		ft_vector3_magn(t_vector3 pVec);
double		ft_vector4_magn(t_vector4 pVec);
void		invert(t_vector3 *pVec);
void		normalize(t_vector3 *pVec);
void		addVector(t_vector3 *pVec, const t_vector3 *pAddVec);
void		subtractVector(t_vector3 *pVec, const t_vector3 *pSubVec);
int			crossMultiplyVectors(const t_vector3 *pVec1, const t_vector3 *pVec2,
				t_vector3 *pResult);
