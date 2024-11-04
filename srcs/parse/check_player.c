/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:53:24 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/04 09:24:31 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_multiple_players(t_game *game)
{
	int		i[3];

	i[0] = 0;
	i[2] = 0;
	while (i[0] < game->map->map_size.height)
	{
		i[1] = 0;
		while (i[1] < game->map->map_size.width)
		{
			if (ft_chrcmp_str(game->map->map[i[0]][i[1]], "NEWS") >= 0)
				if (++i[2] > 1)
					return (ft_printf_fd(2, " - Multiple player.\n"), 1);
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

static double	get_player_angle(char c)
{
	if (c == 'N')
		return (3 * M_PI / 2);
	else if (c == 'E')
		return (0);
	else if (c == 'S')
		return (M_PI / 2);
	else if (c == 'W')
		return (M_PI);
	return (-1);
}

int	get_player_pos(t_game *game)
{
	int		i[2];

	ft_printf_fd(1, "Checking player.\n");
	i[0] = 0;
	while (game->map->map[i[0]][0])
	{
		i[1] = 0;
		while (game->map->map[i[0]][i[1]])
		{
			if (ft_chrcmp_str(game->map->map[i[0]][i[1]], "NEWS") >= 0)
			{
				game->player->angle = \
					get_player_angle(game->map->map[i[0]][i[1]]);
				ft_printf_fd(1, "Pos x: %d | Pos y: %d\n", i[1], i[0]);
				game->player->pos = ft_vector2(i[1] * T_SIZE + CENTER, i[0] * T_SIZE + CENTER);
				game->player_init_pos = game->player->pos;
				ft_printf_fd(1, " - Correct.\n");
				return (0);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (1);
}
