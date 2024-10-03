/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:56:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/30 15:51:59 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void rotate_player(t_game *game, int rot)
{
	if (rot == 1)
		game->player->angle += ROTATION_SPEED;
	else if (rot == -1)
		game->player->angle -= ROTATION_SPEED;
}

void move_player(t_game *game, double move_x, double move_y)
{
	int  map_grid_y;
	int  map_grid_x;
	int  new_x;
	int  new_y;

	new_x = roundf(game->player->pos.x + move_x); // get the new x position
	new_y = roundf(game->player->pos.y + move_y); // get the new y position
	map_grid_x = (new_x / T_SIZE); // get the x position in the map
	map_grid_y = (new_y / T_SIZE); // get the y position in the map
	if (game->map->map[map_grid_y][map_grid_x] != '1' && \
	(game->map->map[map_grid_y][map_grid_x] != '1' && \
	game->map->map[map_grid_y][map_grid_x] != '1')) // check the wall hit and the diagonal wall hit
	{
		game->player->pos.x = new_x; // move the player
		game->player->pos.y = new_y; // move the player
	}
}

void hook(t_game *game)
{
	t_vector2 move;

	rotate_player(game, game->player->rot); // rotate the player
	if (game->player->l_r == 1) // move right
		move = ft_vector2(-sin(game->player->angle) * PLAYER_SPEED, 
						  cos(game->player->angle) * PLAYER_SPEED);
	else if (game->player->l_r == -1) // move left
	move = ft_vector2(sin(game->player->angle) * PLAYER_SPEED, 
					 -cos(game->player->angle) * PLAYER_SPEED);
	if (game->player->u_d == 1) // move up
		move = ft_vector2(cos(game->player->angle) * PLAYER_SPEED, 
						sin(game->player->angle) * PLAYER_SPEED);
	else if (game->player->u_d == -1) // move down
		move = ft_vector2(-cos(game->player->angle) * PLAYER_SPEED, 
						  -sin(game->player->angle) * PLAYER_SPEED);
	move_player(game, move.x, move.y); // move the player
}
