/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:12:31 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/30 09:50:31 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

/** Substitute for parser once completed */
/* static char	**create_example_map(t_game *game)
{
	char	**map2d;

	game->map_size = ft_vector2(10, 25);
	map2d = ft_calloc(game->map_size.height, sizeof(char *));
	map2d[0] = strdup("111111111111111111111111");
	map2d[1] = strdup("100000000000000000000001");
	map2d[2] = strdup("100000000000000000000001");
	map2d[3] = strdup("100000000000000000000001");
	map2d[4] = strdup("100000000000000000000001");
	map2d[5] = strdup("100000000000000000000001");
	map2d[6] = strdup("100000000000E00000000001");
	map2d[7] = strdup("100000000000000000000001");
	map2d[8] = strdup("100000000000000000000001");
	map2d[9] = strdup("111111111111111111111111");
	// map2d[0] = strdup("111111111111111111111111");
	// map2d[1] = strdup("100000010001010001000001");
	// map2d[2] = strdup("100000011001010011000001");
	// map2d[3] = strdup("100000001101010110000001");
	// map2d[4] = strdup("100000000101010100000001");
	// map2d[5] = strdup("100000000000000000000001");
	// map2d[6] = strdup("100000001100E00110000001");
	// map2d[7] = strdup("100000000010001000000001");
	// map2d[8] = strdup("100000000001010000000001");
	// map2d[9] = strdup("111111111111111111111111");
	return (map2d);
} */

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
	//game->matrix = create_example_map(game);	
	game->ray = calloc(1, sizeof(t_ray));
	game->mlx.p_mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.p_mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	game->frame.image = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	player_data(game);
	init_color_textures(game);
	return (game);
}

int	update(t_game *game)
{
	// hook(game->mlx, 0, 0);
	cast_rays(game);
	PRINT_DEBUG("Funcion [%s]: Pre-image to screen", __func__);
	// mlx_put_image_to_window(&game->mlx.p_mlx, &game->mlx.window, &game->frame.image, 0, 0);
	PRINT_DEBUG("Funcion [%s] Final:", __func__);
	return (0);
}

void	engine(t_game *game)
{
	game = init(game);
	// mlx_key_hook(game->mlx.p_mlx, &update, (void *)&game->mlx);
	PRINT_DEBUG("Funcion [%s]: Map pos [%0.2f][%0.2f]", __func__, game->player_pos.x, game->player_pos.y);
	mlx_key_hook(game->mlx.window, read_keys, game);
	mlx_hook(game->mlx.window, 17, 0, end_program, &game->mlx);
	mlx_loop_hook(game->mlx.p_mlx, &update, &game->mlx);
	mlx_loop(game->mlx.p_mlx);
}
