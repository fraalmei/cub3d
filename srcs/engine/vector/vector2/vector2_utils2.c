/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/15 08:59:10 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector2.h>

t_vector2   ft_v2div(t_vector2 v1, t_vector2 v2)
{
    t_vector2   v;

    v.x = v1.x / v2.x;
    v.y = v1.y / v2.y;

    return v;
}

t_vector2   ft_v2fdiv(t_vector2 v1, float f)
{
    t_vector2   v;

    v.x = v1.x / f;
    v.y = v1.y / f;

    return v;
}

double  ft_v2mag(t_vector2 v)
{
    return (v.x * v.x + v.y * v.y);
}

double  ft_v2sqrtmag(t_vector2 v)
{
    return (sqrtf(v.x * v.x + v.y * v.y));
}

t_bool ft_v2eqv(t_vector2 v1, t_vector2 v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}
