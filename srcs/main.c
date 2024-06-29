/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/29 17:29:52 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	leaks(void)
{
	system("leaks -q cub3d");
}
	//atexit(leaks);

int	main(int argc, char **argv)
{
	t_game		*game;

	atexit(leaks);
	if (argc != 2)
	{
		ft_printf_fd(2, "Numero de argumentos incorrecto %s.\n", *argv[1]);
		return (0);
	}
	game = init_data();
	if (check_scene(game, argv[1]))
	{
		ft_printf_fd(2, "Error de mapa.\n");
		return (1);
	}
	print_global(game);
	free_data(game);
	return (0);
}

/* int	main(void)
{
	t_game	*game;

	atexit(leaks);
	game = ft_calloc(1, sizeof(t_game));
	// parser(game);
	engine(game);
	return (0);
} */
