/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/25 15:31:06 by p                ###   ########.fr       */
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
	t_game		*game;

	// atexit(leaks);
	if (argc != 2)
		return (ft_printf_fd(2, "Number of arguments wrong %s.\n", \
			*argv[1]), 0);
	game = init_data();
	if (check_scene(game, argv[1]))
		return (ft_printf_fd(2, "Map error.\n"),1);
	print_global(game);
	// engine(game);
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
