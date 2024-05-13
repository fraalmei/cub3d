/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2024/04/13 19:32:37 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	leaks(void)
{
	system("leaks -q cub3D");
}
	//atexit(leaks);

int	main(int argc, char **argv)
{
	atexit(leaks);
	/* (void) argc;
	(void) argv; */
	ft_printf_fd(1, "Numero de argumentos: %d\n", argc);
	if (argc != 2)
	{
		ft_printf_fd(2, "Numero de argumentos incorrecto.\n");
		return (0);
	}
	if (check_scene(argv[1]))
	{
		ft_printf_fd(2, "Error de mapa.\n");
		return (1);
	}
	return (0);
}

/* int	main(void)
{
	engine();
	atexit(leaks);
	return (0);
}
 */