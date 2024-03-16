/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:33:55 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/16 14:31:33 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_g_textures
{
	void		*no_texture;
	void		*so_texture;
	void		*we_texture;
	void		*ea_texture;
	void		*f_texture;
	void		*c_texture;
}				t_g_textures;

int	init_g_textures(void)
{
	t_g_textures	*textures;

	textures = (t_g_textures *)ft_calloc(sizeof(*textures), 1);
	if (!textures)
		return (1);
	textures->no_texture = NULL;
	textures->so_texture = NULL;
	textures->we_texture = NULL;
	textures->ea_texture = NULL;
	textures->f_texture = NULL;
	textures->c_texture = NULL;
	return (0);
}

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


/// @brief first check the format 
/// second check the archivo is readable
/// and check the elements writed in the map
/// @param map 
/// @return 0 if the maps its correct
int	check_map(char map)
{
	int		file;

	ft_printf("Checking map.\n");
	ft_printf(" - Checking extension.\n");
	if (ft_str_last_cmp(map, ".cub"))
		return (1);
	ft_printf(" - Correct.\n");
	ft_printf(" - Checking readable file.\n");
	file = open(map, O_RDONLY);
	if (file < 0 || read(file, 0, 0) < 0)
		return (close (file), 1);
	ft_printf(" - Correct.\n");
	if (check_elements(file))
		return (1);
	return (0);
}
