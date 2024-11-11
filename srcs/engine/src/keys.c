/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:37:58 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/11 10:58:43 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void	read_keys_check(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS))
		end_program(game);
	else if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_Q)
			game->player->l_r = -1;
		else if (keydata.key == MLX_KEY_E)
			game->player->l_r = 1;
		else if (keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_DOWN)
			game->player->u_d = -1;
		else if (keydata.key == MLX_KEY_W
			|| keydata.key == MLX_KEY_UP)
			game->player->u_d = 1;
		else if (keydata.key == MLX_KEY_A
			|| keydata.key == MLX_KEY_LEFT)
			game->player->rot = -1;
		else if (keydata.key == MLX_KEY_D
			|| keydata.key == MLX_KEY_RIGHT)
			game->player->rot = 1;
	}
	key_release(keydata, game);
}

void	key_release(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
			game->player->l_r = 0;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_W)
			game->player->u_d = 0;
		else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
			game->player->u_d = 0;
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
			game->player->rot = 0;
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
			game->player->rot = 0;
	}
}

// void	read_mouse_check(mouse_key_t button, action_t action,
// 						modifier_key_t mods, void *param)
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
