/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:45:38 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 13:00:11 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	printv2(t_vector2 v)
{
	printf("%f %f \n", v.x, v.y);
}

void	printv3(t_vector3 v)
{
	printf("%f %f %f \n", v.x, v.y, v.z);
}

void	printv4(t_vector4 v)
{
	printf("%f %f %f %f \n", v.x, v.y, v.z, v.w);
}
