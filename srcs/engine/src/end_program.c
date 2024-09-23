/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:39:57 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/23 14:00:05 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/* Frees all allocated memory and makes exit(0) */
void	end_program(void *g)
{
	t_game	*game;

	game = g;
	if (game->mlx.img)
		mlx_delete_image(game->mlx.p_mlx, game->mlx.img);
	mlx_close_window(game->mlx.p_mlx);
	mlx_terminate(game->mlx.p_mlx);
	free_data(game);
	exit(EXIT_SUCCESS);
}
