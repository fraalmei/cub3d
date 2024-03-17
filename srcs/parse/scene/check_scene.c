/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:11:41 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/17 14:33:46 by fraalmei         ###   ########.fr       */
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

	ft_printf("Checking scene\n");
	if (check_extension(file, ".cub"))
		return (1);
	fd = check_readable(file);
	if (fd < 0)
		return (1);
	if (check_elements(fd))
		return (1);
	/*if (check_map(fd))
		return (1); */
	ft_printf("Scene correct\n");
	return (0);
}
