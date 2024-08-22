/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:56:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/08/22 13:41:37 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/**
 * @brief Maneja la entrada del usuario.
 * 
 * @param keycode Código de la tecla presionada.
 * @param game Puntero a la estructura del juego.
 * @return int Siempre devuelve 0.
 */
int move(int keycode, t_game *game)
{
	PRINT_DEBUG("Funcion [%s]: Entrada", __func__);
	game->player.advance = 0;
	game->player.turn = 0;
	if (keycode == K_ESC)
		end_program(game);
	else if (keycode == K_W || keycode == K_UP)
		game->player.advance = 1;
	else if (keycode == K_S || keycode == K_DOWN)
		game->player.advance = -1;
	if (keycode == K_D || keycode == K_RIGHT)
		game->player.turn = 1;
	else if (keycode == K_A || keycode == K_LEFT)
		game->player.turn = -1;
	calc_move(keycode, game);
	PRINT_DEBUG("Funcion [%s]: Final | Player advance [%f]: turn [%f]", __func__, game->player.advance, game->player.turn);
	return (0);
}
int	stop(int keycode, t_game *game)
{
	if (keycode == K_W || keycode == K_UP ||
				keycode == K_S || keycode == K_DOWN)
		game->player.advance = 0;
	else if (keycode == K_A || keycode == K_LEFT ||
				keycode == K_D || keycode == K_RIGHT)
		game->player.turn = 0;
	calc_move(keycode, game);
	PRINT_DEBUG("Funcion [%s]: Final | Player advance [%f]: turn [%f]", __func__, game->player.advance, game->player.turn);
	return (0);
}


void calc_move(int keycode, t_game * game)
{
	double to_x;
	double to_y;

	to_x = 0;
	to_y = 0;
	if (keycode == K_W || keycode == K_UP)
	{
		to_y = (game->player.advance * (game->player.speed_m
				* sin(game->player.angle))) + game->player.pos.x;
		to_x = (game->player.advance * (game->player.speed_m
				* cos(game->player.angle))) + game->player.pos.y;
	}
	else if (keycode == K_S || keycode == K_DOWN)
	{
		to_y = (game->player.advance * (game->player.speed_m
				* sin(game->player.angle))) + game->player.pos.x;
		to_x = (game->player.advance * (game->player.speed_m
				* cos(game->player.angle))) + game->player.pos.y;
	}
	else
	{
		to_x = game->player.pos.x;
		to_y = game->player.pos.y;
	}
	to_y += 0.5;
	to_x += 0.5;
	late_update(game, to_y, to_x);
}

int	can_move(t_game *game, int to_x, int to_y)
{
	int	player_x;
	int	player_y;
	
	player_x = game->player.pos.x;
	player_y = game->player.pos.y;
	PRINT_DEBUG("Funcion [%s]: Inicio | Player Pos[%d, %d] | To Pos[%d, %d]", __func__, player_x, player_y, to_x, to_y);
	PRINT_DEBUG("Funcion [%s]: Inicio | Matrix Values [1->%c, 2->%c, 3->%c]", __func__, game->matrix[to_x][to_y], game->matrix[player_x][to_y], game->matrix[to_x][player_y]);
	if (game->matrix[to_x][to_y] == '1')
		return (0);
	else if (game->matrix[player_x][to_y] == '1'
				&& game->matrix[to_x][player_y] == '1')
		return (0);
	return (1);
}

void late_update(t_game *game, double to_x, double to_y)
{
	int x = floor(to_x);
	int y = floor(to_y);
	
	game->player.angle += game->player.turn * game->player.speed_t;
	if (game->player.angle > (2 * M_PI) || game->player.angle < 0)
		angle(game);
	// if(can_move(game, floor(to_x), floor(to_y)))
	// 	game->player.pos = ft_vector2(to_x, to_y);
	// // render_frame(game);
	PRINT_DEBUG("Funcion [%s]: Finalización | Player Pos[%d, %d]: Angle[%0.7f] | Matrix Value[%d, %d]->[%c]", __func__, 
		(int)game->player.pos.x, (int)game->player.pos.y, game->player.angle, x, y, '1' /*game->matrix[x][y]*/);
}