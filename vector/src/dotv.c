/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:03:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:50:26 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	ft_dotv2(t_vector2 v1, t_vector2 v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float	ft_dotv3(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float	ft_dotv4(t_vector4 v1, t_vector4 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}
