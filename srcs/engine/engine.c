/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:12:31 by cagonzal          #+#    #+#             */
/*   Updated: 2024/04/14 15:13:33 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/engine.h"

void	engine(void)
{
	t_game			game;
	unsigned int	color_white;
	unsigned int	background_color;
	// int				x;
	// int				y;

	color_white = 0xFFFFFF;
	background_color = 0x000000;
	game.map = ft_vector3(4, 4, 1);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Wolfenstein 3D Map");
	game.data.img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	game.data.addr = mlx_get_data_addr(game.data.img, &game.data.bpp, \
					&game.data.line_length, &game.data.endian);
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
	generate_map(game);
	// mlx_put_image_to_window(game.mlx, game.window, game.data.img, 0, 0);
	mlx_hook(game.window, 17, 0, end_program, (void *)&game);
	mlx_loop(game.mlx);
}
