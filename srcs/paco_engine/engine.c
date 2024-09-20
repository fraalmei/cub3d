/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:57:18 by fraalmei          #+#    #+#             */
/*   Updated: 2024/09/20 15:24:28 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	end_check_program(t_game *game)
{
	game->mlx.p_mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.p_mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	game->frame.image = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	return (game);
}

int	end_program(t_game *game)
{
	(void)game;
	mlx_clear_window(game->mlx.p_mlx, game->mlx.window);
	mlx_destroy_window(game->mlx.p_mlx, game->mlx.window);
	free_data(game);
	exit(EXIT_SUCCESS);
}

static int	change_img(t_game *game)
{
	static int	i;

	if (i > 3 || i < 0)
		i = 0;
	if (game->window.img)
		mlx_delete_image(game->window.mlx, game->window.img);
	if (game->map->map_textures[i]->png_img != NULL)
		game->window.img = mlx_texture_to_image(game->window.mlx, game->map->map_textures[i]->png_img);
	if (mlx_image_to_window(game->window.mlx, game->window.img, 0, 0) < 0)
		end_check_program(game);
	i++;
	return (0);
}

static t_game	*init_check(t_game *game)
{
	game->window.mlx = mlx_init(800, 600, "Cub3D", 1);
	if (game->window.mlx == NULL)
		end_check_program(game);
	change_img(game);
	return (game);
}

static void	read_keys_check(mlx_key_data_t keydata, void *param)
{
	t_game			*data;
	char			*str;

	ft_printf_fd(1, "Pulsa tecla\n");
	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
		(ft_printf_fd(1, "Pulsado tecla teclado %d\n", keydata.key), end_check_program(data));
	if ((keydata.key >= 0)&& keydata.action == 1)
	{
		str = (char *)ft_calloc(sizeof(char), 100);
		sprintf(str, "Pulsado tecla teclado %d\n", keydata.key);
		(ft_printf_fd(1, str), change_img(data));
		mlx_put_string(data->window.mlx, str, 0, 0);
		free (str);
	}
}

static void	read_mouse_check(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_game			*data;
	char			*str;

	ft_printf_fd(1, "Pulsa tecla\n");
	data = (t_game *)param;
	if (key_pressed == K_ESC || !data->mlx.window)
		(ft_printf_fd(1, "Pullsado ESC\n"), end_program(data));
	return (0);
}

void	engine_check(t_game *game)
{
	game = init_check(game);
	mlx_key_hook(game->window.mlx, &read_keys_check, game);
	mlx_mouse_hook(game->window.mlx, &read_mouse_check, game);
	mlx_loop(game->window.mlx);
}
