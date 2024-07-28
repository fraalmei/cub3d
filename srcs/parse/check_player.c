/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:53:24 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/28 16:57:25 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static double	get_player_angle(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'E')
		return (90);
	else if (c == 'S')
		return (180);
	else if (c == 'W')
		return (270);
	return (-1);
}

int	get_player_pos(t_game *game)
{
	int		i[2];

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
				game->player->init_grid_pos[0] = i[0];
				game->player->init_grid_pos[1] = i[1];
				return (0);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (1);
}
