/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:53:58 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/07 12:38:28 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4_H
# define VECTOR4_H

typedef union   u_vector4
{
    struct
    {
        double  x;
        double  y;
        double  z;
        double  w;
    };

    struct
    {
        double  r;
        double  g;
        double  b;
        double  a; 
    };
    
    double      elements[4];
    
}  t_vector4;

typedef union   u_matrix4
{
	float	    elements[4][4];
	t_vector4	columns[4];
}	t_matrix4;

t_vector4 ft_vector4(double x, double y, double z, double w);
t_vector4 ft_freevector4(t_vector4 v);
t_vector4 ft_v4add(t_vector4 v1, t_vector4 v2);
t_vector4 ft_v4subs(t_vector4 v1, t_vector4 v2);
t_vector4 ft_v4mult(t_vector4 v1, t_vector4 v2);
t_vector4 ft_v4fmult(t_vector4 v1, float f);
t_vector4 ft_v4div(t_vector4 v1, t_vector4 v2);
t_vector4 ft_v4fdiv(t_vector4 v1, float f);
double ft_v4mag(t_vector4 v);
double ft_v4sqrtmag(t_vector4 v);

#endif

t_vector4 ft_vector4(double x, double y, double z, double w)
{
    t_vector4 vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
}

t_vector4 ft_v4add(t_vector4 v1, t_vector4 v2)
{
    t_vector4 v;

    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;

    return v;
}

t_vector4 ft_v4subs(t_vector4 v1, t_vector4 v2)
{
    t_vector4 v;

    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;

    return v;
}

t_vector4 ft_v4mult(t_vector4 v1, t_vector4 v2)
{
    t_vector4 v;

    v.x = v1.x * v2.x;
    v.y = v1.y * v2.y;
    v.z = v1.z * v2.z;

    return v;
}

t_vector4 ft_v4fmult(t_vector4 v1, float f)
{
    t_vector4 v;

    v.x = v1.x * f;
    v.y = v1.y * f;
    v.z = v1.z * f;

    return v;
}


t_vector4 ft_v4div(t_vector4 v1, t_vector4 v2)
{
    t_vector4 v;

    v.x = v1.x / v2.x;
    v.y = v1.y / v2.y;
    v.z = v1.z / v2.z;

    return v;
}


t_vector4 ft_v4fdiv(t_vector4 v1, float f)
{
    t_vector4 v;

    v.x = v1.x / f;
    v.y = v1.y / f;
    v.z = v1.z / f;

    return v;
}


double ft_v4mag(t_vector4 v)
{
    return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}


double ft_v4sqrtmag(t_vector4 v)
{
    return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}