/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:27:37 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/12 17:41:52 by p                ###   ########.fr       */
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

static t_texture	*get_texture(t_textures *textures, char *name)
{
	ft_printf_fd(1, "Obteniendo textura\n");
	if (!ft_strcmp(textures->t_no->name, name))
		return (textures->t_no);
	if (!ft_strcmp(textures->t_so->name, name))
		return (textures->t_so);
	if (!ft_strcmp(textures->t_we->name, name))
		return (textures->t_we);
	if (!ft_strcmp(textures->t_ea->name, name))
		return (textures->t_ea);
	if (!ft_strcmp(textures->t_f->name, name))
		return (textures->t_f);
	if (!ft_strcmp(textures->t_c->name, name))
		return (textures->t_c);
	return (NULL);
}

static int	read_texture(t_textures *textures, char *line, char ***sides)
{
	char		*side;
	t_texture	*texture;

	side = get_word(line, 0);
	texture = get_texture(textures, side);
	ft_printf_fd(1, "Comprobando textura %s\n", side);
	if (check_side(side, sides) && !texture)
	{
		ft_printf_fd(2, "Varios elementos iguales o no existentes: %s\n", side);
		return (1);
	}
	*sides = del_node_arr(*sides, side);
	texture->dir = get_word(line, 1); // Problem here
	if (!texture->dir)
		return (1);
	/* if (check_texture(*texture, side))
		return (1); */
	ft_printf_fd(1, "Textura obtenida %s\n", texture->dir);
	return (0);
}

int	check_elements(int fd)
{
	char		*line;
	char		**sides;
	t_textures	*textures;
	int			i;

	ft_printf_fd(1, " - Checking elements.\n");
	textures = set_textures();
	sides = set_sides();
	i = ft_arraylen((const void **)sides);
	while (i--)
	{
		line = get_next_notempty_line(fd);
		if (!read_texture(textures, line, &sides))
			return (free_textures(textures), 1);
		free (line);
	}
	ft_printf_fd(1, "Comprobadas texturas\n");
	if (sides)
		free_arr ((void **)sides);
	free_textures(textures);
	ft_printf_fd(1, "Elements - Correct.\n");
	return (0);
}
