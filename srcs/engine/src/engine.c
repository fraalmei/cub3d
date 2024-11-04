/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:12:31 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/04 09:52:04 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>

/**
 * @brief Function to count the frames
 * and print the player position and rotation
 * 
 * @param game Game structure
 */
void frame_counter(t_game *game)
{
	if (game->n_frame++ > 60)
		game->n_frame = 0;
}

/**
 * @brief Function to update the game
 * 			- Clear the image
 * 			- Update game logic
 * 			- Update game rendering
 * 			- Show the image
 * 
 * @param g Game structure
 */
void	update(void *g)
{
	t_game	*game;
	
	game = g;
    frame_counter(game);
	mlx_delete_image(game->mlx.p_mlx, game->mlx.img);
	game->mlx.img = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	hook(game);
	cast_rays(game);
	mlx_image_to_window(game->mlx.p_mlx, game->mlx.img, 0, 0);
}

/**
 * @brief Function to initialize the game engine
 * 			- Initialize the ray and MLX structure
 * 			- Set the loop hook	
 * 			- Set the key hook - Control keys and mouse
 * 			- Set the loop to show the window
 *
 * @param game Game structure
 */
void	engine(t_game *game)
{
	game->n_frame = 0;
	game->ray = ft_calloc(S_WIDTH, sizeof(t_ray));
	game->mlx.p_mlx = mlx_init(S_WIDTH, S_HEIGHT, "Cub3D", 0);
	mlx_loop_hook(game->mlx.p_mlx, &update, game);
	mlx_key_hook(game->mlx.p_mlx, &read_keys_check, game);
	mlx_loop(game->mlx.p_mlx);
}
