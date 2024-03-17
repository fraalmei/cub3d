/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:05:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 12:49:54 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector3	ft_cross(t_vector3 v1, t_vector3 v2)
{
	t_vector3	v;

	v.x = (v1.y * v2.z) - (v2.y * v1.z);
	v.y = (v1.z * v2.x) - (v2.z * v1.x);
	v.z = (v1.x * v2.y) - (v2.x * v1.y);
	return (v);
}
