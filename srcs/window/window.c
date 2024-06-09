/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:31:43 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/09 17:39:56 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

	// function to create the program (mlx + window)
t_win	new_program(t_size map, t_size img, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, map.width, map.height, \
		str), map, img});
}
