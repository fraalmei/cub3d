/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:34:09 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/25 10:05:26 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

#include "structs.h"

void	init_ray(t_ray *ray, int ray_index, double ray_angle)
{
	ray[ray_index].ray_angle = ray_angle;
	ray[ray_index].ray_dir = ft_vector2(cos(ray[ray_index].ray_angle), sin(ray[ray_index].ray_angle));
	ray[ray_index].delta_dist = ft_vector2(fabs(1 / ray[ray_index].ray_dir.x), fabs(1 / ray[ray_index].ray_dir.y));
}

// Declaración de funciones para cada opción
void esc_function(t_game *game)
{
    printf("Esc keydown\n");
    end_program(game);
}

void space_funcion()
{
    printf("Space keydown\n");
}

void	null_check(void *ptr, const char *message)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: %s\n", message);
		exit(EXIT_FAILURE);
	}
}