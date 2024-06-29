/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:12:31 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/29 20:21:07 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* void	engine(t_game *game)
{
	//unsigned int	color_white;
	//unsigned int	background_color;
	// int				x;
	// int				y;

	//color_white = 0xFFFFFF;
	//background_color = 0x000000;
	// game.map = ft_vector3(4, 4, 1);
	game->mlx.p_mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.p_mlx, S_WIDTH, S_HEIGHT, "Wolfenstein 3D Map");
	game->frame.image = mlx_new_image(game->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	game->frame.add = mlx_get_data_addr(game->frame.image, &game->frame.bpp, \
					&game->frame.length, &game->frame.endian);
	// // Color de fondo (negro en formato BGR)
	// y = 0;
	// while (y < WIN_HEIGHT)
	// {
	// 	x = 0;
	// 	while (x < WIN_WIDTH)
	// 	{
	// 		*(unsigned int *)(game.data.addr + ((y * WIN_WIDTH + x) * 4)) = color_white;
	// 		x++;
	// 	}
	// 	y++;
	// }
	// Genera el laberinto utilizando Recursive Backtracking
	//generate_map(game);
	// mlx_put_image_to_window(game.mlx, game.window, game.data.img, 0, 0);
	mlx_hook(game->mlx.window, 17, 0, end_program, (void *)&game);
	mlx_loop(game->mlx.p_mlx);
}
 */