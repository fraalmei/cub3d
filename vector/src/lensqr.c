/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lensqr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:33:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:57:03 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	ft_lensqrv2(t_vector2 v)
{
	return (v.x * v.x + v.y * v.y);
}

float	ft_lensqrv3(t_vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float	ft_lensqrv4(t_vector4 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
