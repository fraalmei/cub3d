/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectdivf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:42:34 by cagonzal          #+#    #+#             */
/*   Updated: 2024/04/13 17:08:12 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect.h>

t_vector2	ft_vector2_fmult(t_vector2 v1, float single)
{
	t_vector2	vr;

	vr.x = v1.x / single;
	vr.y = v1.y / single;
	return (vr);
}

t_vector3	ft_vector3_fmult(t_vector3 v1, float single)
{
	t_vector3	vr;

	vr.x = v1.x / single;
	vr.y = v1.y / single;
	vr.z = v1.z / single;
	return (vr);
}

t_vector4	ft_vector4_fmult(t_vector4 v1, float single)
{
	t_vector4	vr;

	vr.x = v1.x / single;
	vr.y = v1.y / single;
	vr.z = v1.z / single;
	vr.w = v1.w / single;
	return (vr);
}
