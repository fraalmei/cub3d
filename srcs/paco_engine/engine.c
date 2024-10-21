/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:57:18 by fraalmei          #+#    #+#             */
/*   Updated: 2024/10/11 14:31:45 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	end_check_program(t_game *game)
{
	game->mlx.p_mlx = mlx_init();
	game->mlx.img = mlx_new_window(game->mlx.p_mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	game->frame.image = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	return (game);
}

int	paco_end_program(t_game *game)
{
	(void)game;
	if (game->mlx.img)
		mlx_delete_image(game->mlx.p_mlx, game->mlx.img);
	mlx_close_window(game->mlx.p_mlx);
	mlx_terminate(game->mlx.p_mlx);
	free_data(game);
	exit(EXIT_SUCCESS);
}

static int	paco_change_img(t_game *game)
{
	static int	i;

	if (i > 3 || i < 0)
		i = 0;
	if (game->mlx.img)
		mlx_delete_image(game->mlx.p_mlx, game->mlx.img);
	if (game->map->map_textures[i]->png_img != NULL)
		game->mlx.img = mlx_texture_to_image(game->mlx.p_mlx, game->map->map_textures[i]->png_img);
	if (mlx_image_to_window(game->mlx.p_mlx, game->mlx.img, 0, 0) < 0)
		paco_end_program(game);
	i++;
	return (0);
}

static t_game	*paco_init_check(t_game *game)
{
	game->mlx.p_mlx = mlx_init(800, 600, "Cub3D", 1);
	if (game->mlx.p_mlx == NULL)
		paco_end_program(game);
	paco_change_img(game);
	return (game);
}

static void	paco_read_keys_check(mlx_key_data_t keydata, void *param)
{
	t_game			*data;
	char			*str;

	ft_printf_fd(1, "Pulsa tecla\n");
	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
		(ft_printf_fd(1, "Pulsado tecla teclado %d\n", keydata.key), paco_end_program(data));
	if ((keydata.key >= 0)&& keydata.action == 1)
	{
		str = (char *)ft_calloc(sizeof(char), 100);
		sprintf(str, "Pulsado tecla teclado %d\n", keydata.key);
		(ft_printf_fd(1, str), paco_change_img(data));
		mlx_put_string(data->mlx.p_mlx, str, 0, 0);
		free (str);
	}
}

static void	paco_read_mouse_check(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_game			*data;
	char			*str;

	(void) action;
	(void) mods;
	(void) button;
	ft_printf_fd(1, "Pulsa tecla\n");
	data = (t_game *)param;
	if ((button >= 0)&& action == 1)
	{
		str = (char *)ft_calloc(sizeof(char), 100);
		sprintf(str, "Pulsado tecla teclado %d\n", button);
		(ft_printf_fd(1, str), paco_change_img(data));
		mlx_put_string(data->mlx.p_mlx, str, 0, 0);
		free (str);
	}
}

void	engine_check(t_game *game)
{
	game = paco_init_check(game);
	mlx_key_hook(game->mlx.p_mlx, &paco_read_keys_check, game);
	mlx_mouse_hook(game->mlx.p_mlx, &paco_read_mouse_check, game);
	mlx_loop(game->mlx.p_mlx);
}
