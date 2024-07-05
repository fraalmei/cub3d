/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/11 15:08:04 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

static void	player_data_aux(t_game *game, int pos_x, int pos_y, char value)
{
	t_vector2	new_pos;
	float		center;

	center = T_SIZE / 2;
	if (value == 'N' || value == 'S' || value == 'W' || value == 'E')
	{
		new_pos = ft_vector2(pos_x * T_SIZE + center, pos_y * T_SIZE + center);
		game->player.pos = new_pos;
		game->player.angle = 0;
		game->player.fov_rd = FOV_RAD;
		game->matrix[pos_x][pos_y] = '0';
		if (value == 'N')
			game->player.angle = 3 * M_PI / 2;
		else if (value == 'S')
			game->player.angle = (M_PI / 2);
		else if (value == 'W')
			game->player.angle = (M_PI);
	}
}

void	player_data(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = -1;
	while (++pos_x < game->map_size.x)
	{
		pos_y = -1;
		while (++pos_y < game->map_size.y)
			if (game->matrix[pos_x][pos_y] != '1')
				player_data_aux(game, pos_x, pos_y, game->matrix[pos_x][pos_y]);
	}
	game->player_pos = game->player.pos;
	PRINT_DEBUG("Funcion [%s]: Final | Pos[%f][%f] | FOV_RD [%0.7f] | Angle [%0.7f]", __func__, game->player_pos.x, game->player_pos.y, game->player.fov_rd, game->player.angle);
}
