/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:39:57 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/19 12:03:48 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	if (!game->win.p_mlx)
	{
		if (game->win.img)
			mlx_delete_image(game->win.p_mlx, game->win.img);
		mlx_close_window(game->win.p_mlx);
		mlx_terminate(game->win.p_mlx);
		free_data(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
