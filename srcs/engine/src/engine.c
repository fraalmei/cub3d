/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:12:31 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/20 15:30:47 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>

/** Change for texture loading */
void	init_color_textures(t_game *game)
{
	game->roof_color = extract_color(ft_vector3(135, 206, 235));
	game->floor_color = extract_color(ft_vector3(50, 50, 50));
	game->north_texture = extract_color(ft_vector3(255, 5, 5));
	game->east_texture = extract_color(ft_vector3(5, 255, 5));
	game->south_texture = extract_color(ft_vector3(5, 5, 255));
	game->west_texture = extract_color(ft_vector3(25, 25, 25));

}

t_game	*init(t_game *game)
{
	game->ray = calloc(1, sizeof(t_ray));
	game->mlx.p_mlx = mlx_init(S_WIDTH, S_HEIGHT, "Cub3D", 0);
	// player_data(game);
	init_color_textures(game);
	return (game);
}

void	update(void *g)
{
	t_game	*game;

	game = g;
	mlx_delete_image(game->mlx.p_mlx, game->mlx.img);
	game->mlx.img = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	// Update game logic
	// hook(game->mlx, 0, 0);
	// Update 
	cast_rays(game);
	mlx_image_to_window(game->mlx.p_mlx, game->mlx.img, 0, 0);
	PRINT_DEBUG("Funcion [%s] Final:", __func__);
}

void	engine(t_game *game)
{
	game = init(game);
	mlx_loop_hook(game->mlx.p_mlx, &update, game);
	// Control keys and mouse
	mlx_key_hook(game->mlx.p_mlx, &read_keys_check, game);
    mlx_mouse_hook(game->mlx.p_mlx, &read_mouse_check, game);
	// Control program exit
	mlx_loop(game->mlx.p_mlx); 
}
