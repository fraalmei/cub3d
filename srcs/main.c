/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/16 17:00:23 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	leaks(void)
{
	system("leaks -q cub3D");
}
	//atexit(leaks);

// int	main(int argc, char **argv)
// {
// 	(void)argv;
// 	if (argc != 2)
// 	{
// 		ft_printf_fd(2, "Numero de argumentos incorrecto.\n");
// 		return (0);
// 	}
// 	check_scene(argv[1]);
// 	atexit(leaks);
// 	return (0);
// }

int	main(void)
{
	engine();
	atexit(leaks);
	return (0);
}
