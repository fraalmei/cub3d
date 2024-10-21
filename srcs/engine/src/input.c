/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:56:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/10/21 11:03:24 by cagonzal         ###   ########.fr       */
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
	t_vector2 new_pos;
	char **map;
	int map_grid_x;
	int map_grid_y;

	map = game->map->map; // get the map
	new_pos = ft_addv2(game->player->pos, ft_vector2(move_x, move_y)); // get the new position
	map_grid_x = (int)floor(new_pos.x / T_SIZE); // get the x position in the map
	map_grid_y = (int)floor(new_pos.y / T_SIZE); // get the y position in the map
	// PRINT_DEBUG("Map grid[%d][%d] = %c\n", map_grid_y, map_grid_x, map[map_grid_y][map_grid_x]);
	if (map[map_grid_y][map_grid_x] != '1') // check the wall hit
		game->player->pos = new_pos; // move the player
}

void hook(t_game *game)
{
	t_vector2 move;

	move = ft_vector2(0, 0);
	rotate_player(game, game->player->rot); // rotate the player
	game->player->angle = nor_angle(game->player->angle); // normalize the angle
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
