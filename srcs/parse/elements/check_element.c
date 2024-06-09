/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:27:37 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/09 16:10:18 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static char	**set_sides(void)
{
	char	**ret;

	ret = ft_split("NO;SO;WE;EA;F;C", ';');
	return (ret);
}

static int	read_texture(t_game *data, char *line, char ***sides)
{
	char	*side;
	char	*texture;

	side = get_word(line, 0);
	if (check_side(side, sides))
	{
		ft_printf_fd(2, "Varios elementos iguales o no existentes: %s\n", side);
		return (1);
	}
	*sides = del_node_arr(*sides, side);
	texture = get_word(line, 1);
	if (!texture)
		return (1);
	if (check_texture(data, texture, side))
		return (1);
	return (0);
}

int	check_elements(t_game *data, int fd)
{
	char	*line;
	char	**sides;
	int		i;

	ft_printf_fd(1, " - Checking elements.\n");
	sides = set_sides();
	i = ft_arraylen((const void **)sides);
	while (i--)
	{
		line = get_next_notempty_line(fd);
		if (!read_texture(data, line, &sides))
			return (1);
		free (line);
	}
	if (sides)
		free_arr ((void **)sides);
	ft_printf_fd(1, "Elements - Correct.\n");
	return (0);
}
