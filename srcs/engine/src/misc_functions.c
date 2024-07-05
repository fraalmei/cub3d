/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:34:09 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/30 09:50:25 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void image_update(t_game * game)
{
	game->frame.image = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	game->frame.add = mlx_get_data_addr(game->frame.image, &game->frame.bpp,
		&game->frame.length, &game->frame.endian);
	game->mnmap.image = mlx_new_image(game->mlx.p_mlx, game->map_size.width * T_SIZE,
		game->map_size.height * T_SIZE);
	game->mnmap.add = mlx_get_data_addr(game->mnmap.image, &game->mnmap.bpp,
		&game->mnmap.length, &game->mnmap.endian);
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
