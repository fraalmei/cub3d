/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/16 16:14:19 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	leaks(void)
{
	system ("leaks -q cub3D");
}
	//atexit(leaks);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf_fd(2, "Numero de argumentos incorrecto.\n");
		return (0);
	}
	check_scene(argv[1]);
	atexit(leaks);
	return (0);
}
