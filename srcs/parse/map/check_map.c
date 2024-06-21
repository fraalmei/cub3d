/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:33:55 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/21 11:38:37 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
static int	check_walls(int file)
{
	return (0);
}
/// @brief 
/// @param line 
/// @return 
static int	check_coordinate(char *line, char **cords)
{
	char			*word;
	int				i;

	i = 0;
	word = get_next_word(line, i++);
	if (ft_strcmp(cords[i], word))
		return (ft_printf("Wrong coordinate %s.\n", word), free(word), 1);
	del_node_arr(cords, word);
	free (word);
	word = get_next_word(line, i);
	if (!mlx_xpm_file_to_image(NULL, word, 0, 0))
		return (ft_printf("Wrong texture file.\n"), free(word), 1);
	free (word);
}

/// @brief 
/// @param line 
/// @return 
static int	check_textures(int fd, char *line)
{
	char			**cords;
	int				i;
	int				run_cord;

	cords = str_array("NO SO WE EA F C");
	i = 0;
	while (cords[0])
	{
		if (check_coordinate(line, cords))
			return (1);
	}
	return (0);
}

static int	check_color(char line)
{
	return (0);
}

/// @brief it read the map line to line
/// the first 6 lines of the map contains the textures
/// and the rest is the map
/// @param file 
/// @return 
static int	check_elements(int file)
{
	char	*line;
	int		i;

	i = 0;
	ft_printf(" - Reading file.\n");
	line = get_next_line(file);
	if (!line)
		return (1);
	ft_printf(" - Correct.\n");
	ft_printf(" - Reading textures.\n");
	if (init_g_textures())
		return (1);
	if (check_textures(file, line))
		return (1);
	(free (line), close (file));
	return (0);
}
*/

/* static int	check_empty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]) == 0 || line[i] == 32)
			ft_printf_fd(1, "%c", line[i]), i++;
		else
			return (0);
	}
	return (1);
} */
/* 
static char	**add_str_arr(char **arr, char *str)
{
	char	**swap;
	size_t		i;

	if (!str && !arr)
		return (NULL);
	if (!str && arr)
		return (arr);
	if (str && !arr)
		arr = (char **)ft_calloc(sizeof(char *), 1);
	i = ft_arraybi_size(arr);
	ft_printf("arraylen %d - %s\n", i, str);
	swap = (char **)ft_calloc(sizeof(char *), i + 1);
	i = -1;
	while(arr[++i])
		swap[i] = arr[i];
	swap[i] = str;
	free (arr);
	return (swap);
} */

static char	**map_to_matrix(int fd)
{
	char	**map;
	char	*line;
	char	*swap;

	if (fd == 0)
		return (NULL);
	map = NULL;
	line = get_next_notempty_line(fd);
	swap = ft_strtrim(line, "\n");
	free(line);
	while (swap)
	{
		map = ft_arrayjoin_arrfree(map, swap);
		free(swap);
		line = get_next_line(fd);
		swap = ft_strtrim(line, "\n");
		free(line);
	}
	free(swap);
	return (map);
}

/// @brief first check the format 
/// second check the archivo is readable
/// and check the elements writed in the map
/// @param map 
/// @return 0 if the maps its correct
int	check_map(int fd)
{
	char	**map;

	ft_printf("Checking map.\n");
	map = map_to_matrix(fd);
	if (!map)
		return (1);
	ft_printf(" - - Printing map \n"), print_arr(map);
	ft_printf(" - Correct.\n");
	return (0);
}
