/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:37:58 by fraalmei          #+#    #+#             */
/*   Updated: 2024/09/26 14:26:50 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void read_keys_check(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS) && keydata.action == MLX_REPEAT)
		end_program(game);
	else if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) // move left
			game->player->l_r = -1;
		else if (keydata.key == MLX_KEY_D  || keydata.key == MLX_KEY_RIGHT) // move right
			game->player->l_r = 1;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) // move down
			game->player->u_d = -1;
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) // move up
			game->player->u_d = 1;
		else if (keydata.key == MLX_KEY_Q) // rotate left
			game->player->rot = -1;
		else if (keydata.key == MLX_KEY_E) // rotate right
			game->player->rot = 1;
	}
	key_release(keydata, game);
}

void	key_release(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
			game->player->l_r = 0;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_W)
			game->player->u_d = 0;
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
			game->player->rot = 0;
	}
}

void	player_rotate(t_game *game)
{
	if (game->player->rot)
	{
		game->player->angle += ROTATION_SPEED;
		if (game->player->angle >= 2 * M_PI)
			game->player->angle -= 2 * M_PI;
		else if (game->player->angle < 0)
			game->player->angle += 2 * M_PI;
	}
}

void player_move(t_game *game)
{
	t_vector2	new_pos;
	t_vector2	move;

	move = ft_vector2(PLAYER_SPEED * cos(game->player->angle), PLAYER_SPEED * sin(game->player->angle));
	new_pos = ft_addv2(game->player->pos, move);
	if (wall_hit(game, new_pos.x, game->player->pos.y))
		game->player->pos.x = new_pos.x;
	new_pos = ft_addv2(game->player->pos, ft_vector2(PLAYER_SPEED * cos(game->player->angle + (M_PI / 2)), PLAYER_SPEED * sin(game->player->angle + (M_PI / 2))));
	if (wall_hit(game, game->player->pos.x, new_pos.y))
		game->player->pos.y = new_pos.y;
}

// void read_mouse_check(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
// {
// 	t_game *data;
// 	char *str;
// 	ft_printf_fd(1, "Pulsa tecla\n");
// 	data = (t_game *)param;
// 	(void)mods;
// 	if ((button >= 0) && action == 1)
// 	{
// 		str = (char *)ft_calloc(sizeof(char), 100);
// 		sprintf(str, "Pulsado tecla raton %d\n", button);
// 		// (ft_printf_fd(1, str), change_img(data));
// 		mlx_put_string(data->mlx.p_mlx, str, 0, 0);
// 		free(str);
// 	}
// }
