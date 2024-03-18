/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:12:31 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/18 09:21:47 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	engine(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	image;
	t_vector2 test;

	test = ft_vector2(3.0f, 4.0f);
	(void)test;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	image.img = mlx_new_image(mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, \
					&image.line_length, &image.endian);
	mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
	mlx_loop(mlx);
}
