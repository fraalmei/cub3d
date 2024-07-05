/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:39:57 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/30 09:50:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	(void)game;
	mlx_clear_window(game->mlx.p_mlx, game->mlx.window);
	mlx_destroy_window(game->mlx.p_mlx, game->mlx.window);
	// free_tilemap(game);
	// game->tilemap = NULL;
	// free_enemies(game);
	// game->enemy_list = NULL;
	free_data(game);
	exit(EXIT_SUCCESS);
}
