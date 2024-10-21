/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:56:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/10/21 11:15:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/**
 * @brief Function to rotate the player
 * 
 * @param game Pointer to the game structure
 * @param rot Rotation direction
 */
void rotate_player(t_game *game, int rot)
{
	if (rot == 1)
		game->player->angle += ROTATION_SPEED;
	else if (rot == -1)
		game->player->angle -= ROTATION_SPEED;
}

/**
 * @brief Function to move the player
 * 
 * @param game Pointer to the game structure
 * @param move_x Movement in the x axis
 * @param move_y Movement in the y axis
 */
void move_player(t_game *game, double move_x, double move_y)
{
	t_vector2 new_pos;
	char **map;
	int map_grid_x;
	int map_grid_y;

	map = game->map->map;
	new_pos = ft_addv2(game->player->pos, ft_vector2(move_x, move_y));
	map_grid_x = (int)floor(new_pos.x / T_SIZE);
	map_grid_y = (int)floor(new_pos.y / T_SIZE);
	if (map[map_grid_y][map_grid_x] != '1')
		game->player->pos = new_pos;
}

/**
 * @brief Function to move the player
 * 
 * @param game Pointer to the game structure
 */
void hook(t_game *game)
{
	t_vector2 move;

	move = ft_vector2(0, 0);
	rotate_player(game, game->player->rot);
	game->player->angle = nor_angle(game->player->angle);
	if (game->player->l_r == 1)
		move = ft_vector2(-sin(game->player->angle) * PLAYER_SPEED, 
						  cos(game->player->angle) * PLAYER_SPEED);
	else if (game->player->l_r == -1)
		move = ft_vector2(sin(game->player->angle) * PLAYER_SPEED, 
					 -cos(game->player->angle) * PLAYER_SPEED);
	if (game->player->u_d == 1)
		move = ft_vector2(cos(game->player->angle) * PLAYER_SPEED, 
						sin(game->player->angle) * PLAYER_SPEED);
	else if (game->player->u_d == -1)
		move = ft_vector2(-cos(game->player->angle) * PLAYER_SPEED, 
						  -sin(game->player->angle) * PLAYER_SPEED);
	move_player(game, move.x, move.y);
}
