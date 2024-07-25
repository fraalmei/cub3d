/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:33:55 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/25 14:24:37 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief convert the map into a double array
// check de fd
// read the next existent line
// trim the line
// and read the next line until find a empty line
/// @param fd 
/// @return a double array
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
		if (check_empty_line(swap))
			break ;
		map = ft_arrayjoin_arrfree(map, swap);
		free(swap);
		line = get_next_line(fd);
		swap = ft_strtrim(line, "\n");
		free(line);
	}
	free(swap);
	return (map);
}

/// @brief check if the char its near to the correct char
/// @param map 
/// @param point 
/// @param unique 
/// @param wall 
/// @return a 0 if the char its correct, a 1 if not
static int	check_point(char **map, t_size point, char **unique, char wall)
{
	if (!map || !wall)
		return (1);
	if (map[point.width][point.height] == wall || \
			map[point.width][point.height] == ' ')
		return (0);
	if (ft_del_str_arr_chr_cmp(map[point.width][point.height], &unique))
		return (1);
	if (!map[point.width - 1][point.height] || \
			map[point.width - 1][point.height] == ' ')
		return (1);
	if (!map[point.width][point.height - 1] || \
			map[point.width][point.height - 1] == ' ')
		return (1);
	if (!map[point.width + 1][point.height] || \
			map[point.width + 1][point.height] == ' ')
		return (1);
	if (!map[point.width][point.height + 1] || \
			map[point.width][point.height + 1] == ' ')
		return (1);
	return (0);
}

/// @brief check if the map is correct
// set a string with all sides
// set a string with all characters in the map 
// check all chars of the map 1 by 1
/// @param map 
/// @return a 0 if the map its correct
static int	check_map(char **map)
{
	t_size		p;
	char		**str;
	char		*allc;

	p.width = 0;
	p.height = 0;
	str = ft_split("0NWES", ';');
	allc = ft_strdup("0NEWS01 ");
	if (!map || !map[p.width][p.height])
		return (1);
	while (map[p.width])
	{
		while (map[p.width][p.height])
		{
			if (ft_chrcmp_str(map[p.width][p.height], allc) == -1)
				return (1);
			if (check_point(map, p, str, '1'))
				return (1);
			p.height++;
		}
		p.width++;
		p.height = 0;
	}
	free_arr((void **)str);
	return (0);
}

/// @brief fill the right of the map to set the map a square
/// @param map 
/// @return a 0 if it works
static int	fill_map(char ***map)
{
	int		max_row;
	int		i;
	int		swap_max;

	i = 0;
	max_row = 0;
	while (map[0][i])
	{
		swap_max = 0;
		while (map[0][i][swap_max])
			swap_max++;
		if (swap_max > max_row)
			max_row = swap_max;
		i++;
	}
	i = -1;
	while (map[0][++i])
	{
		swap_max = -1;
		while (++swap_max < max_row)
			if (!map[0][i][swap_max])
				map[0][i] = ft_chrjoin(map[0][i], ' ');
	}
	return (0);
}

/// @brief first check the format 
/// second check the archivo is readable
/// and check the elements writed in the map
/// @param map 
/// @return 0 if the maps its correct
char	**read_map(int fd)
{
	char	**map;

	ft_printf("Checking map.\n");
	map = map_to_matrix(fd);
	if (!map)
		return (NULL);
	if (check_map(map))
		return (NULL);
	ft_printf(" - - Printing map \n");
	fill_map(&map);
	ft_printf(" - Correct.\n");
	return (map);
}
