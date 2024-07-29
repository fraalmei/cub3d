/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:27:37 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/29 15:56:11 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief  check if the string side is in of the array sides
/// @param side 
/// @param sides 
/// @return a 0 if side is in sides, a 1 if not
static int	check_side(char *side, char ***sides)
{
	int		i;
	char	**swap;

	i = -1;
	swap = *sides;
	while (swap[++i])
		if (ft_strcmp(swap[i], side) == 0)
			return (0);
	return (1);
}

/// @brief return a pointer to a structure of a structure array
/// @param textures is the array of textures
/// @param name the name of the texture to find
/// @return a pointer to the texture
static t_texture	*get_texture(t_texture **textures, char *name)
{
	if (!ft_strcmp(textures[0]->name, name))
		return (textures[0]);
	if (!ft_strcmp(textures[1]->name, name))
		return (textures[1]);
	if (!ft_strcmp(textures[2]->name, name))
		return (textures[2]);
	if (!ft_strcmp(textures[3]->name, name))
		return (textures[3]);
	if (!ft_strcmp(textures[4]->name, name))
		return (textures[4]);
	if (!ft_strcmp(textures[5]->name, name))
		return (textures[5]);
	return (NULL);
}

/// @brief read the line to check a texture exist
/// @param texture array of textures
/// @param line the line to read
/// @param sides an array of sides to check the readed sides
/// @return a 0 if the texture its correct, or 1 if an error ocurr
static int	read_texture(t_texture **texture, char *line, char ***sides)
{
	char		*side;
	t_texture	*p_texture;

	side = get_word(line, 0);
	p_texture = get_texture(texture, side);
	//ft_printf_fd(1, " - - Checking texture: %s\n", side);
	if (check_side(side, sides) && !texture)
	{
		ft_printf_fd(2, " - - - Several identical or non-existent elements: %s\n", side);
		return (1);
	}
	*sides = del_node_arr(*sides, side);
	p_texture->dir = get_word(line, 1);
	if (!p_texture->dir)
		return (1);
	//ft_printf_fd(1, " - - Obtained texture: %s\n", p_texture->dir);
	return (0);
}

/// @brief check the next lines of the map to read the textures
/// @param fd the file descriptor of the map
/// @return an array of textures
t_texture	**check_elements(int fd)
{
	char		*line;
	char		**sides;
	t_texture	**textures;
	int			i;

	ft_printf_fd(1, "Checking textures.\n");
	textures = set_textures();
	sides = ft_split("NO;SO;WE;EA;F;C", ';');
	i = ft_arraylen((const void **)sides);
	while (i--)
	{
		line = get_next_notempty_line(fd);
		if (read_texture(textures, line, &sides))
			return (free_textures(textures), \
				ft_printf_fd(2, " - Texture error\n"), NULL);
		free (line);
	}
	if (sides)
		free_arr ((void **)sides);
	ft_printf_fd(1, " - Correct textures.\n");
	return (textures);
}
