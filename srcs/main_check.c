/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:12:40 by p                 #+#    #+#             */
/*   Updated: 2024/08/30 13:59:57 by p                ###   ########.fr       */
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
		return (ft_printf_fd(2, "Number of arguments wrong %d.\n", \
			argc - 1), 0);
	game = init_data();
	if (check_scene(game, argv[1]))
		return (ft_printf_fd(2, "Map error.\n"),1);
	print_global(game);
	engine_check(game);
	free_data(game);
	return (0);
}