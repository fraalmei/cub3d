/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectmult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:42:36 by cagonzal          #+#    #+#             */
/*   Updated: 2024/04/13 17:09:03 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect.h>

t_vector4	ft_vector4_mult(t_vector4 v1, t_vector4 v2)
{
	t_vector4	vr;

	vr.x = v1.x * v2.x;
	vr.y = v1.y * v2.y;
	return (vr);
}

t_vector3	ft_vector3_mult(t_vector3 v1, t_vector3 v2)
{
	t_vector3	vr;

	vr.x = v1.x * v2.x;
	vr.y = v1.y * v2.y;
	vr.z = v1.z * v2.z;
	return (vr);
}

t_vector4	ft_vector4_mult(t_vector4 v1, t_vector4 v2)
{
	t_vector4	vr;

	vr.x = v1.x * v2.x;
	vr.y = v1.y * v2.y;
	vr.z = v1.z * v2.z;
	vr.w = v1.w * v2.w;
	return (vr);
}
