/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:46:41 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/29 15:57:00 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/// @brief check if the extension of the file its correct
/// @param file 
/// @param ext 
/// @return a 0 if its correct, a 1 if not
int	check_extension(char *file, char *ext)
{
	ft_printf("Checking extension file.\n");
	if (ft_str_last_cmp(file, ext))
	{
		ft_printf_fd(2, " - Incorrect extension of the file.\n");
		return (1);
	}
	ft_printf(" - Correct extension.\n");
	return (0);
}

/// @brief open the file and check if is readable
/// @param file 
/// @return return a fd if its readable or a -1 if not
int	check_readable(char *file)
{
	int		fd;

	ft_printf("Checking readable file.\n");
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_printf_fd(2, " - File is not readable.\n");
		close(fd);
		return (ft_printf_fd(2, " - File not readable.\n"), -1);
	}
	ft_printf(" - File readable.\n", file);
	return (fd);
}
