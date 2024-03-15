/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/15 08:48:53 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector2.h>

t_vector2 ft_vector2(double x, double y)
{
    t_vector2 vector;

    vector.x = x;
    vector.y = y;
}

t_vector2 ft_v3add(t_vector2 v1, t_vector2 v2)
{
    t_vector2 v;

    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;

    return v;
}

t_vector2 ft_v3subs(t_vector2 v1, t_vector2 v2)
{
    t_vector2 v;

    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;

    return v;
}

t_vector2 ft_v3mult(t_vector2 v1, t_vector2 v2)
{
    t_vector2 v;

    v.x = v1.x * v2.x;
    v.y = v1.y * v2.y;

    return v;
}

t_vector2 ft_v3fmult(t_vector2 v1, float f)
{
    t_vector2 v;

    v.x = v1.x * f;
    v.y = v1.y * f;

    return v;
}