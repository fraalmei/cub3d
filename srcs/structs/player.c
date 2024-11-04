/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:38:32 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/03 12:13:02 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	print_player_inf(t_player *player)
{
	ft_printf_fd (1, COLOR_GREEN);
	ft_printf_fd (1, "################# PLAYER #################\n");
	ft_printf_fd (1, COLOR_RESET);
	ft_printf_fd(1, "Player information:\n");
	printf(" - Player postion: [%f] [%f]\n", \
		player->pos.elements[0], player->pos.elements[1]);
	printf(" - Player orientation: %lf\n", player->angle);
	ft_printf_fd (1, COLOR_GREEN);
	ft_printf_fd (1, "###########################################\n");
	ft_printf_fd (1, COLOR_RESET);
	return (0);
}

int	set_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	game->player->l_r = 0;
	game->player->u_d = 0;
	game->player->rot = 0;
	game->player->fov_rd = FOV_RAD;
	if (!game->player)
		return (1);
	if (check_multiple_players(game))
		return (1);
	if (get_player_pos(game))
		return (1);
	return (0);
}
