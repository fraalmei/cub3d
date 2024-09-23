/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:37:58 by fraalmei          #+#    #+#             */
/*   Updated: 2024/09/23 08:21:06 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/**
 * @brief Changes the current image displayed in the game window.
 *
 * This function cycles through a set of predefined textures and updates the 
 * game window with the next texture in the sequence. If the current image 
 * exists, it deletes it before loading the new one. The function ensures 
 * that the index stays within the valid range of textures.
 *
 * @param game Pointer to the game structure containing window and texture information.
 * @return Always returns 0.
 */
static int	change_img(t_game *game)
{
	// static int i;
	
	(void)game;
	// i = 0;
	// if (i > 3 || i < 0)
	// 	i = 0;
	// if (game->mlx.img)
	// 	mlx_delete_image(game->mlx.p_mlx, game->mlx.img);
	// if (game->map->map_textures[i])
	// 	game->mlx.img = mlx_texture_to_image(game->mlx.p_mlx, game->map->map_textures[i]->img);
	// if (mlx_image_to_window(game->mlx.p_mlx, game->mlx.img, 0, 0) == -1)
	// 	end_program(game);
	// i++;
	return (0);
}

void read_keys_check(mlx_key_data_t keydata, void *param)
{
	t_game		*data;
	char		*str;

	ft_printf_fd(1, "Pulsa tecla\n");
	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
		(ft_printf_fd(1, "Pulsado tecla teclado %d\n", keydata.key), end_program(data));
	if ((keydata.key >= 0)&& keydata.action == 1)
	{
		str = (char *)ft_calloc(sizeof(char), 100);
		sprintf(str, "Pulsado tecla teclado %d\n", keydata.key);
		// (ft_printf_fd(1, str), change_img(data));
		mlx_put_string(data->mlx.p_mlx, str, 0, 0);
		free (str);
	}
}
void read_mouse_check(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
    t_game          *data;
    char            *str;
    ft_printf_fd(1, "Pulsa tecla\n");
    data = (t_game *)param;
    (void) mods;
    if ((button >= 0)&& action == 1)
    {
        str = (char *)ft_calloc(sizeof(char), 100);
        sprintf(str, "Pulsado tecla raton %d\n", button);
        (ft_printf_fd(1, str), change_img(data));
        mlx_put_string(data->mlx.p_mlx, str, 0, 0);
        free (str);
    }
}
