/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:33:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/17 23:20:53 by p                ###   ########.fr       */
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
	free_map (game);
	free (game->player);
	free (game);
	return (0);
}

int	print_global(t_game *game)
{
	if (game->map)
		print_map(game->map);
	if (game->player)
		print_player_inf(game->player);
	return (0);
}
