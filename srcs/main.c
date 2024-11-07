/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/07 17:41:38 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// print_global(game);

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
		return (ft_printf_fd(2, "Number of arguments wrong %d.\n", \
			argc - 1), 0);
	game = init_data();
	if (check_scene(game, argv[1]))
		return (free_data(game), 1);
	engine(game);
	free_data(game);
	return (0);
}
