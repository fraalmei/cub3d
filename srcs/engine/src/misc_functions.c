/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:34:09 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/20 13:56:58 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

#include "structs.h"

void	init_ray(t_ray *ray, int ray_index, double ray_angle)
{
	ray->ray = ray_index;
	ray->flag = 0; // 0 means no wall hit
	ray->ray_angle = ray_angle;
	ray->dist = 0.0;
	// ray->hit = ft_vector2(0.0, 0.0);
	// Initialize other fields if needed
	// ray->point = 0.0;
	// ray->wall = 0.0;
	// ray->ray_at = ray_index;
	// ray->hor = false;
	// ray->ver = false;
	// ray->h = (t_vector2){0.0, 0.0};
	// ray->step = (t_vector2){0.0, 0.0};
	// ray->v = (t_vector2){0.0, 0.0};
	// ray->map = (t_vector2){0.0, 0.0};
	// ray->r = (t_vector2){0.0, 0.0};
	// ray->dof = 0.0;
	// ray->disth = 0.0;
	// ray->distv = 0.0;
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
