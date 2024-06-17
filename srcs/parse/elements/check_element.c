/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:27:37 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/17 10:20:05 by p                ###   ########.fr       */
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

static t_texture	*get_texture(t_texture **textures, char *name)
{
	ft_printf_fd(1, "Obteniendo textura\n");
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

static int	read_texture(t_texture **texture, char *line, char ***sides)
{
	char		*side;
	t_texture	*p_texture;

	side = get_word(line, 0);
	p_texture = get_texture(texture, side);
	ft_printf_fd(1, "Comprobando textura %s\n", side);
	if (check_side(side, sides) && !texture)
	{
		ft_printf_fd(2, "Varios elementos iguales o no existentes: %s\n", side);
		return (1);
	}
	*sides = del_node_arr(*sides, side);
	p_texture->dir = get_word(line, 1);
	if (!p_texture->dir)
		return (1);
	/* if (check_texture(*texture, side))
		return (1); */
	ft_printf_fd(1, "Textura obtenida %s\n", p_texture->dir);
	return (0);
}

int	check_elements(int fd)
{
	char		*line;
	char		**sides;
	t_texture	**textures;
	int			i;

	ft_printf_fd(1, " - Checking elements.\n");
	textures = set_textures();
	sides = set_sides();
	i = ft_arraylen((const void **)sides);
	while (i--)
	{
		line = get_next_notempty_line(fd);
		if (read_texture(textures, line, &sides))
			return (free_textures(textures), 1);
		free (line);
	}
	ft_printf_fd(1, "Comprobadas texturas\n");
	if (sides)
		free_arr ((void **)sides);
	print_textures(textures);
	free_textures(textures);
	ft_printf_fd(1, "Elements - Correct.\n");
	return (0);
}
