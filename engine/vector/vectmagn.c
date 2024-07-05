/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectmagn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:23 by cagonzal          #+#    #+#             */
/*   Updated: 2024/04/13 17:10:11 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect.h>

double	ft_vector2_magn(t_vector2 v)
{
	return (sqrt(ft_vector2_sqrmagn(v)));
}

double	ft_vector3_magn(t_vector3 v)
{
	return (sqrt(ft_vector3_sqrmagn(v)));
}

double	ft_vector4_magn(t_vector4 v)
{
	return (sqrt(ft_vector4_sqrmagn(v)));
}
