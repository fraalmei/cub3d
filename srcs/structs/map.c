/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:21:48 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/29 20:39:46 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	print_map(t_map *map)
{
	ft_printf_fd (1, COLOR_CYAN);
	ft_printf_fd (1, "################# TEXTURES #################\n");
	ft_printf_fd (1, COLOR_RESET);
	print_textures(map->map_textures);
	ft_printf_fd (1, COLOR_BLUE);
	ft_printf_fd (1, "################### MAP ###################\n");
	ft_printf_fd (1, COLOR_RESET);
	print_arr(map->map);
	printf("\nTile size: [%f] [%f]\n", \
		map->tile_size.width, map->tile_size.height);
	printf("Map size: [%li] [%li]\n", \
		map->map_size.height, map->map_size.width);
	ft_printf_fd (1, COLOR_BLUE);
	ft_printf_fd (1, "###########################################\n");
	ft_printf_fd (1, COLOR_RESET);
	return (0);
}

int	free_map(t_game *game)
{
	free_textures(game->map->map_textures);
	free_arr((void **)game->map->map);
	ft_printf_fd(1, "Map freed.\n");
	return (0);
}

int	set_map(t_game *game, int fd)
{
	game->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!game->map)
		return (1);
	game->map->tile_size.width = T_SIZE;
	game->map->tile_size.height = T_SIZE;
	game->map->map_textures = check_elements(fd);
	if (!game->map->map_textures)
		return (1);
	game->map->map = read_map(fd);
	if (!game->map->map)
		return (1);
	game->map->map_size = matrix_len(game->map->map);
	return (0);
}
