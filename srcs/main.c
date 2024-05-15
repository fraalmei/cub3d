/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2024/05/15 17:36:52 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* static void	leaks(void)
{
	system("leaks -q cub3d");
} */
	//atexit(leaks);

int	main(int argc, char **argv)
{
	//atexit(leaks);
	/* (void) argc;
	(void) argv; */
	if (argc != 2)
	{
		ft_printf_fd(2, "Numero de argumentos incorrecto.\n");
		system("leaks -q cub3d");
		return (1);
	}
	if (check_scene(argv[1]))
	{
		ft_printf_fd(2, "Error de mapa.\n");
		system("leaks -q cub3d");
		return (1);
	}
	//system("leaks -q cub3d");
	return (0);
}

/* int	main(void)
{
	engine();
	atexit(leaks);
	return (0);
}
 */