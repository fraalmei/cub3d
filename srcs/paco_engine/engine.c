/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:57:18 by fraalmei          #+#    #+#             */
/*   Updated: 2024/08/31 17:45:34 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	end_check_program(t_game *game)
{
	//mlx_close_window(game->mlx.p_mlx);
	//mlx_destroy_window(game->mlx.p_mlx, game->mlx.p_mlx->window);
	mlx_close_window(game->mlx.p_mlx);
    mlx_terminate(game->mlx.p_mlx);
	free_data(game);
	ft_printf_fd(1, "Se finaliza ventana\n");
	exit(EXIT_SUCCESS);
}

static t_game	*init_check(t_game *game)
{
	ft_printf_fd(1, "Se inicia ventana\n");
	game->mlx.p_mlx = mlx_init(S_WIDTH, S_HEIGHT, "Cub3D", 0);
	if (game->mlx.p_mlx)
		end_check_program(game);
	//game->mlx.p_mlx->window = mlx_new_window(game->mlx.p_mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	//game->frame.image = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	return (game);
}

/*
static int	read_keys_check(int key_pressed, void *param)
{
	t_game			*data;

	data = (t_game *)param;
	if (key_pressed == K_ESC || !data->mlx.p_mlx)
		(ft_printf_fd(1, "Pulsado ESC\n"), end_check_program(data));
	return (0);
}*/

void	engine_check(t_game *game)
{
	game = init_check(game);
	//mlx_loop_hook(game->mlx.p_mlx, &update, &game->mlx.p_mlx); // game loop continuously call a specified function to update the game state and render the frames.
	//mlx_key_hook(game->mlx.p_mlx->window, read_keys_check, game); // key press and release
	mlx_loop(game->mlx.p_mlx); // mlx loop
}
