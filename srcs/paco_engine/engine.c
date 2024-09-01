/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:57:18 by fraalmei          #+#    #+#             */
/*   Updated: 2024/09/01 17:49:16 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	end_check_program(t_game *game)
{
	if (game->window.img)
		mlx_delete_image(game->window.mlx, game->window.img);
	ft_printf_fd(1, "Pulsado ESC\n");
	mlx_close_window(game->window.mlx);
	mlx_terminate(game->window.mlx);
	free_data(game);
	exit(EXIT_SUCCESS);
}

static int	change_img(t_game *game)
{
	static int	i;

	if (i > 3 || i < 0)
		i = 0;
	ft_printf_fd(1, "Cambia de imagen %d\n", i);
	wait(1000);
	if (game->window.img)
		mlx_delete_image(game->window.mlx, game->window.img);
	if (game->map->map_textures[i]->png_img != NULL)
		game->window.img = mlx_texture_to_image(game->window.mlx, game->map->map_textures[i]->png_img);
	if (mlx_image_to_window(game->window.mlx, game->window.img, 0, 0) < 0)
		end_check_program(game);
	ft_printf_fd(1, "Muestra imagen %d\n", i);
	i++;
	return (0);
}

static t_game	*init_check(t_game *game)
{
	game->window.mlx = mlx_init(800, 600, "Cub3D", 1);
	if (game->window.mlx == NULL)
		end_check_program(game);
	change_img(game);
	//game->window.mlx->window = mlx_new_window(game->window.mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	//game->frame.image = mlx_new_image(game->window.mlx, S_WIDTH, S_HEIGHT);
	return (game);
}

static int	read_keys_check(void *param)
{
	t_game			*data;


	ft_printf_fd(1, "Pulsa tecla\n");
	data = (t_game *)param;
	//if (key_pressed == K_ESC || !data->window.mlx)
	if (mlx_is_key_down(data->window.mlx, K_ESC) || !data->window.mlx)
		(ft_printf_fd(1, "Pulsado ESC\n"), end_check_program(data));
	if (mlx_is_key_down(data->window.mlx, K_SPACE))
		(ft_printf_fd(1, "Pulsado ESP\n"), change_img(data));
	return (0);
}

static int	check_update(void *param)
{
	t_game			*game;

	ft_printf_fd(1, "Pulsa tecla\n");
	game = (t_game *)param;
/* 	ft_printf_fd(1, "Actualiza cambio imagen\n");
	if (game->window.img)
		mlx_delete_image(game->window.mlx, game->window.img);
	//hook(game->window, 0, 0);
	// cast_rays(game);
	change_img(game);
	ft_printf_fd(1, "Cambió imagen\n"); */
	return (0);
}

void	engine_check(t_game *game)
{
	xpm_t	*swap;

	game = init_check(game);
	//mlx_loop_hook(game->window.mlx, 17, 0, &end_check_program, &game->window);
	mlx_key_hook(game->window.mlx, read_keys_check, game); // key press and release
	//mlx_loop_hook(game->window.mlx, check_update, game); // game loop continuously call a specified function to update the game state and render the frames.

	mlx_loop(game->window.mlx); // mlx loop
}
