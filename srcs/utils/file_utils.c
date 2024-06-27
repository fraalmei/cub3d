/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:46:41 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/21 15:53:07 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**set_double_arr(char *str, char c)
{
	char	**ret;

	ret = ft_split(str, c);
	return (ret);
}

int	check_extension(char *file, char *ext)
{
	ft_printf(" - Checking extension file.\n");
	if (ft_str_last_cmp(file, ext))
	{
		ft_printf_fd(2, "Incorrect extension of the file.\n");
		return (1);
	}
	ft_printf(" - Correct.\n");
	return (0);
}

int	check_readable(char *file)
{
	int		fd;

	ft_printf(" - Checking readable file.\n");
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_printf_fd(2, "\033[0;31mFile is not readable.\n\033[0m");
		close(fd);
		return (-1);
	}
	ft_printf("%s - Correct.\n", file);
	return (fd);
}
