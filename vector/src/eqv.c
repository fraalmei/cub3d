/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eqv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:57:52 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:56:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

bool	ft_eqv2(t_vector2 v1, t_vector2 v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}

bool	ft_eqv3(t_vector3 v1, t_vector3 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

bool	ft_eqv4(t_vector4 v1, t_vector4 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w);
}
