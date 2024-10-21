/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:12:31 by cagonzal          #+#    #+#             */
/*   Updated: 2024/10/21 11:03:45 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>

/** Change for texture loading */
// void	init_color_textures(t_game *game)
// {
// 	game->roof_color = 0x87CEEBFF; // sky blue
// 	game->floor_color = 0x7EC850FF; // grass green
// 	game->north_texture = 0xB5B5B5FF; // red
// 	game->east_texture = 0x808080FF; // green
// 	game->south_texture = 0xB5B5B5FF; // blue
// 	game->west_texture = 0x808080FF; // grey

// }

t_game	*init(t_game *game)
{
	game->ray = calloc(S_WIDTH, sizeof(t_ray));
	game->mlx.p_mlx = mlx_init(S_WIDTH, S_HEIGHT, "Cub3D", 0);
	// init_color_textures(game);
	return (game);
}

void	update(void *g)
{
	t_game	*game;
	
	game = g;
    frame_counter(game);
	PRINT_DEBUG("Player pos[%f][%f]\n", game->player->pos.x, game->player->pos.y);
	PRINT_DEBUG("Player_rot in degrees = %d\n", (int)floor(game->player->angle * 180 / M_PI));
    // Clear the image
	mlx_delete_image(game->mlx.p_mlx, game->mlx.img);
	game->mlx.img = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	// Update game logic
	hook(game);
	// Update game rendering
	cast_rays(game);
	mlx_image_to_window(game->mlx.p_mlx, game->mlx.img, 0, 0);
	// PRINT_DEBUG("Funcion [%s] End:", __func__);
}

void	engine(t_game *game)
{
	game = init(game);
	mlx_loop_hook(game->mlx.p_mlx, &update, game);
	// Control keys and mouse
	mlx_key_hook(game->mlx.p_mlx, &read_keys_check, game);
	// Control program exit
	mlx_loop(game->mlx.p_mlx);
}
