/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:57:18 by fraalmei          #+#    #+#             */
/*   Updated: 2024/09/13 12:43:29 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*init(t_game *game)
{
	game->win.p_mlx = mlx_init();
	game->win.window = mlx_new_window(game->win.p_mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	game->frame.image = mlx_new_image(game->win.p_mlx, S_WIDTH, S_HEIGHT);
	return (game);
}

int	end_program(t_game *game)
{
	(void)game;
	mlx_clear_window(game->win.p_mlx, game->win.window);
	mlx_destroy_window(game->win.p_mlx, game->win.window);
	free_data(game);
	exit(EXIT_SUCCESS);
}

int	read_keys(int key_pressed, void *param)
{
	t_game			*data;

	data = (t_game *)param;
	if (key_pressed == K_ESC || !data->win.window)
		(ft_printf_fd(1, "Pullsado ESC\n"), end_program(data));
	return (0);
}

void	engine(t_game *game)
{
	game = init(game);	
	mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx); // game loop continuously call a specified function to update the game state and render the frames.
	mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx); // key press and release
	mlx_loop(mlx.mlx_p); // mlx loop
}
