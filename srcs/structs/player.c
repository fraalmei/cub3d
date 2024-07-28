/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:38:32 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/28 17:47:50 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	print_player_inf(t_player *player)
{
	ft_printf_fd (1, COLOR_GREEN);
	ft_printf_fd (1, "################# PLAYER #################\n");
	ft_printf_fd (1, COLOR_RESET);
	ft_printf_fd(1, "Player information:\n");
	printf(" - Player postion: [%i] [%i]\n", \
		player->init_grid_pos[0], player->init_grid_pos[1]);
	printf(" - Player orientation: %lf\n", player->angle);
	ft_printf_fd(1, "Player rotation:\n");
	ft_printf_fd (1, COLOR_GREEN);
	ft_printf_fd (1, "###########################################\n");
	ft_printf_fd (1, COLOR_RESET);
	return (0);
}

int	set_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return (1);
	if (get_player_pos(game))
		return (1);
	return (0);
}
