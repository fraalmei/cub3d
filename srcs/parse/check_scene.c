/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:11:41 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/28 17:25:45 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief first check the format 
/// second check the archivo is readable
/// and check the elements writed in the map
/// @param t_game
/// @param file 
/// @return 0 if the maps its correct
int	check_scene(t_game *game, char *file)
{
	int	fd;

	ft_printf_fd(1, "Checking scene.\n");
	if (check_extension(file, ".cub"))
		return (1);
	fd = check_readable(file);
	if (fd < 0)
		return (1);
	if (set_map(game))
		return (1);
	game->map->map_textures = check_elements(fd);
	if (!game->map->map_textures)
		return (1);
	game->map->map = read_map(fd);
	if (!game->map->map)
		return (1);
	if (set_player(game))
		return (ft_printf_fd(2, " - Player error.\n"), 1);
	close (fd);
	ft_printf_fd(1, "Scene correct.\n");
	return (0);
}
