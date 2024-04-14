/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:39:57 by cagonzal          #+#    #+#             */
/*   Updated: 2024/04/13 20:56:22 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/engine.h"
#include <cub3d.h>

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	free(game);
	// free_tilemap(game);
	// game->tilemap = NULL;
	// free_enemies(game);
	// game->enemy_list = NULL;
	exit(0);
}
