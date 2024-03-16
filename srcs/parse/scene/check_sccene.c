/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sccene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:11:41 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/16 14:31:16 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *file, char *ext)
{
	ft_printf(" - Checking extension file.\n");
	if (ft_str_last_cmp(file, ".cub"))
	{
		ft_frintf_fd(2, "Incorrect extension of the file.\n");
		return (1);
	}
	ft_printf(" - Correct.\n");
	return (0);
}

int	check_readable(char *file)
{
	ft_printf(" - Checking readable file.\n");
	file = open(file, O_RDONLY);
	if (file < 0 || read(file, 0, 0) < 0)
	{
		ft_printf("File is not readable.\n");
		close (file);
		return (1);
	}
	ft_printf(" - Correct.\n");
	return (0);
}

// @brief first check the format 
/// second check the archivo is readable
/// and check the elements writed in the map
/// @param file 
/// @return 0 if the maps its correct
int	check_scene(char *file)
{
	int		file;

	ft_printf("Checking scene\n");
	if (check_extension(file, ".cub"))
		return (1);
	if (check_readable(file))
		return (1);
	if (check_elements(file))
		return (1);
	if (check_map(file))
		return (1);
	ft_printf("Scene correct\n");
	return (0);
}
