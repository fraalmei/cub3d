/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:39:57 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/24 11:07:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	(void)game;
	// mlx_clear_window(game->p_mlx.p_mlx, game->p_mlx.screen);
	// mlx_destroy_window(game->p_mlx.p_mlx, game->p_mlx.screen);
	// free_tilemap(game);
	// game->tilemap = NULL;
	// free_enemies(game);
	// game->enemy_list = NULL;
	// free(game);
	exit(0);
	return (0);
}
