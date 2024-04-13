/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectmagn2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:23 by cagonzal          #+#    #+#             */
/*   Updated: 2024/04/13 17:10:50 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect.h>

double	ft_vector2_sqrmagn(t_vector2 v)
{
	return (v.x * v.x + v.y * v.y);
}

double	ft_vector3_sqrmagn(t_vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	ft_vector4_sqrmagn(t_vector4 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
