/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:27:37 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/17 15:15:21 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*check_texture(char *line)
{
	char	*word;

	word = get_word(line, 1);
	if (check_image(word))
		return (NULL);
	ft_printf ("texture -> %s\n", word);
	return (word);
}

static char	*check_side(char *line, char ***sides)
{
	char	*word;

	word = get_word(line, 0);
	*sides = del_node_arr(*sides, word);
	print_str_str(*sides);
	return (word);
}

static char	**set_sides(void)
{
	char	**ret;

	ret = ft_split("NO;SO;WE;EA;F;C", ';');
	return (ret);
}

static char	*check_textures(char *line, char ***sides)
{
	char	*side;
	char	*texture;

	texture = get_word(line, 2);
	if (texture)
	{
		ft_printf ("Datos con de textura con argumentos extra\n");
		free (texture);
		return (NULL);
	}
	free (texture);
	side = check_side(line, sides);
	texture = check_texture(line);
	return (texture);
}

int	check_elements(int fd)
{
	char	*line;
	char	*texture;
	char	**sides;

	sides = set_sides();
	line = get_next_line(fd);
	texture = check_textures(line, &sides);
	free (line);
	return (0);
}
