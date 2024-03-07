/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:03 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/07 12:47:40 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector2.h>

t_vector2 ft_v3div(t_vector2 v1, t_vector2 v2)
{
    t_vector2 v;

    v.x = v1.x / v2.x;
    v.y = v1.y / v2.y;

    return v;
}

t_vector2 ft_v3fdiv(t_vector2 v1, float f)
{
    t_vector2 v;

    v.x = v1.x / f;
    v.y = v1.y / f;

    return v;
}

double ft_v3mag(t_vector2 v)
{
    return (v.x * v.x + v.y * v.y);
}

double ft_v3sqrtmag(t_vector2 v)
{
    return (sqrtf(v.x * v.x + v.y * v.y));
}