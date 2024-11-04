/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:27:37 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/04 09:40:04 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
static int	read_texture(t_texture **texture, char *line, t_str_fndd **list)
{
	char		*side;
	t_texture	*p_texture;

	side = get_word(line, 0);
	p_texture = get_texture(texture, side);
	if (check_list(side, list))
	{
		ft_printf_fd(2, " - - Several identical or non-existent elements.\n");
		return (free(side), 1);
	}
	free(side);
	p_texture->dir = get_word(line, 1);
	if (!p_texture->dir)
		return (1);
	if (check_images(p_texture))
		return (1);
	return (0);
}

/// @brief check the next lines of the map to read the textures
/// @param fd the file descriptor of the map
/// @return an array of textures
t_texture	**check_elements(int fd)
{
	char		*line;
	t_str_fndd	**sides;
	t_texture	**textures;
	int			i;

	ft_printf_fd(1, "Checking textures.\n");
	textures = set_textures();
	sides = set_list_to_find("NO;SO;WE;EA;F;C", ';');
	i = str_fndd_list_len(sides);
	while (i--)
	{
		line = get_next_notempty_line(fd);
		if (read_texture(textures, line, sides))
			return (free_textures(textures), free_list (sides), free (line), \
				NULL);
		free (line);
	}
	if (check_true_list(sides))
		return (ft_printf_fd(1, " - Texture missing.\n"), free_list (sides), NULL);
	free_list (sides);
	ft_printf_fd(1, " - Correct textures.\n");
	return (textures);
}
