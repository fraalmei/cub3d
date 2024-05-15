/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:27:37 by fraalmei          #+#    #+#             */
/*   Updated: 2024/05/15 11:34:40 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static char	*check_texture(char *line)
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
} */

static char	**set_sides(void)
{
	char	**ret;

	ret = ft_split("NO;SO;WE;EA;F;C", ';');
	return (ret);
}

static char	*read_texture(char *line, char ***sides)
{
	//char	*side;
	char	*texture;

	(void) sides;
	texture = get_word(line, 7);
	if (!texture)
		return (NULL);
	/* free (texture);
	side = check_side(line, sides);
	texture = check_texture(line); */
	return (texture);
}

int	check_elements(int fd)
{
	char	*line;
	char	*texture;
	char	**sides;

	(void) fd;
	sides = set_sides();
	line = get_next_line(fd);
	texture = read_texture(line, &sides);
	ft_printf_fd(1, "Textura: %s\n", texture);
	free (texture);
	print_arr(sides);
	free_arr ((void **)sides);
	free (line);
	return (0);
}
