/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:53:58 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/07 12:37:33 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# define Vector3_right ft_vector3(1.0f, 0.0f, 0.0f)
# define Vector3_up ft_vector3(0.0f, 1.0f, 0.0f)
# define Vector3_forward ft_vector3(0.0f, 0.0f, 1.0f)
# define Vector3_left ft_vector3(-1.0f, 0.0f, 0.0f)
# define Vector3_down ft_vector3(0.0f, -1.0f, 0.0f)
# define Vector3_back ft_vector3(0.0f, 0.0f, -1.0f)

typedef union u_vector3
{
    struct
    {
        double x;
        double y;
        double z;
    };

    struct
    {
        double u;
        double v;
        double w;
    };

    struct
    {
        double r;
        double g;
        double b;
    };

    struct
    {
        double width;
        double heigth;
        double depth;
    };
    
    double elements[3];
    
}  t_vector3;

typedef union u_matrix3
{
	float	elements[3][3];
	t_vector3	columns[3];
}	t_matrix3;

t_vector3 ft_vector3(double x, double y, double z);
t_vector3 ft_v3add(t_vector3 v1, t_vector3 v2);
t_vector3 ft_v3subs(t_vector3 v1, t_vector3 v2);
t_vector3 ft_v3mult(t_vector3 v1, t_vector3 v2);
t_vector3 ft_v3fmult(t_vector3 v1, float f);
t_vector3 ft_v3div(t_vector3 v1, t_vector3 v2);
t_vector3 ft_v3fdiv(t_vector3 v1, float f);
double ft_v3mag(t_vector3 v);
double ft_v3sqrtmag(t_vector3 v);

#endif

t_vector3 ft_vector3(double x, double y, double z)
{
    t_vector3 vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
}

t_vector3 ft_v3add(t_vector3 v1, t_vector3 v2)
{
    t_vector3 v;

    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;

    return v;
}

t_vector3 ft_v3subs(t_vector3 v1, t_vector3 v2)
{
    t_vector3 v;

    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;

    return v;
}

t_vector3 ft_v3mult(t_vector3 v1, t_vector3 v2)
{
    t_vector3 v;

    v.x = v1.x * v2.x;
    v.y = v1.y * v2.y;
    v.z = v1.z * v2.z;

    return v;
}

t_vector3 ft_v3fmult(t_vector3 v1, float f)
{
    t_vector3 v;

    v.x = v1.x * f;
    v.y = v1.y * f;
    v.z = v1.z * f;

    return v;
}


t_vector3 ft_v3div(t_vector3 v1, t_vector3 v2)
{
    t_vector3 v;

    v.x = v1.x / v2.x;
    v.y = v1.y / v2.y;
    v.z = v1.z / v2.z;

    return v;
}


t_vector3 ft_v3fdiv(t_vector3 v1, float f)
{
    t_vector3 v;

    v.x = v1.x / f;
    v.y = v1.y / f;
    v.z = v1.z / f;

    return v;
}


double ft_v3mag(t_vector3 v)
{
    return (v.x * v.x + v.y * v.y + v.z * v.z);
}


double ft_v3sqrtmag(t_vector3 v)
{
    return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}
