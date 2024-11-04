/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:33:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/04 11:44:44 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*init_data(void)
{
	t_game		*data;

	data = ft_calloc(sizeof(t_game), 1);
	if (!data)
		return (NULL);
	return (data);
}

int	free_data(t_game *game)
{
	ft_printf_fd (1, COLOR_YELLOW);
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd(1, "################### FREEING GAME ###################\n");
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, COLOR_RESET);
	free_map (game);
	ft_printf_fd(1, "Map freed.\n");
	free (game->player);
	ft_printf_fd(1, "Player freed.\n");
	free (game);
	ft_printf_fd (1, COLOR_YELLOW);
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd(1, "#################### GAME FREED ####################\n");
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, COLOR_RESET);
	return (0);
}

int	print_global(t_game *game)
{
	ft_printf_fd (1, COLOR_YELLOW);
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, "################## PRINTING DATA ##################\n");
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, COLOR_RESET);
	if (game->map)
		print_map(game->map);
	if (game->player)
		print_player_inf(game->player);
	ft_printf_fd (1, COLOR_YELLOW);
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, "################### DATA PRINTED ##################\n");
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, COLOR_RESET);
	return (0);
}
