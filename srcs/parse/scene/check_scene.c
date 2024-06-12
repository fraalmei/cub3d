/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:11:41 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/10 17:21:40 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// @brief first check the format 
/// second check the archivo is readable
/// and check the elements writed in the map
/// @param file 
/// @return 0 if the maps its correct
int	check_scene(char *file)
{
	int	fd;

	ft_printf_fd(1, "Checking scene\n");
	if (check_extension(file, ".cub"))
		return (1);
	fd = check_readable(file);
	if (fd < 0)
		return (1);
	if (check_elements(fd))
		return (1);
	/*if (check_map(fd))
		return (1); */
	ft_printf_fd(1, "Scene correct\n");
	return (0);
}
