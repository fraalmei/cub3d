/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:33:55 by fraalmei          #+#    #+#             */
/*   Updated: 2023/12/04 12:29:57 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/// @brief check the map format, looking the last characters of the map name
/// @param map 
/// @return 
static int	check_format(char map)
{
	if (ft_str_last_cmp(map, ".cub"))
		return (1);
	return (0);
}

static int	check_walls(int file)
{
	return (0);
}

/// @brief 
/// @param line 
/// @return 
static int	check_textures(int fd, char line)
{
	char			**cords;
	char			*cord;
	int				i;
	int				run_cord;

	i = 0;
	cords = str_array("NO SO WE EA F C");
	while (cord && i < 4)
	{
		run_cord = 0;
		cord = get_next_word(line, i);
		while (run_cord)
		{
			if (ft_strcmp(cord, cords[run_cord++]) == 0)
			{
				del_node_arr(cords, cord);
				if (check_image(get_next_word(line, i)))
					return (1);
			}
		}
	}
	cord = get_next_word(line, i);
	if (detect_image_size(cord) == NULL)
		return (1);
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
	line = get_next_line(file);
	if (!line)
		return (1);
	if (check_textures(file, line))
		return (1);
	(free (line), close (file));
	return (0);
}


/// @brief first check the format 
/// second check the archivo is readable
/// and check the elements writed in the map
/// @param map 
/// @return 0 if the maps its correct
int	check_map(char map)
{
	int		file;

	if (check_format(map))
		return (1);
	file = open(map, O_RDONLY);
	if (file < 0 || read(file, 0, 0) < 0)
		return (close (file), 1);
	if (check_elements(file))
		return (1);
	return (0);
}
