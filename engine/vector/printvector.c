/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printvector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:00:08 by cagonzal          #+#    #+#             */
/*   Updated: 2024/04/13 16:59:59 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect.h>

void	printvector2(t_vector2 v)
{
	printf("[%5f,  %5f]\n", v.x, v.y);
}

void	printvector3(t_vector3 v)
{
	printf("[%5f,  %5f,  %5f]\n", v.x, v.y, v.z);
}

void	printvector4(t_vector4 v)
{
	printf("[%5f,  %5f,  %5f,  %5f]\n", v.x, v.y, v.z, v.w);
}
