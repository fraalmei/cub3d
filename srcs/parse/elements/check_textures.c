/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:12:40 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/17 10:21:06 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*set_texture(char *name)
{
	t_texture	*texture;

	texture = (t_texture *)ft_calloc(sizeof(t_texture *), 1);
	texture->name = name;
	return (texture);
}

t_texture	**set_textures(void)
{
	t_texture	**textures;

	textures = (t_texture **)ft_calloc(sizeof(t_texture *), 6);
	textures[0] = set_texture(ft_strdup("NO"));
	textures[1] = set_texture(ft_strdup("SO"));
	textures[2] = set_texture(ft_strdup("WE"));
	textures[3] = set_texture(ft_strdup("EA"));
	textures[4] = set_texture(ft_strdup("F"));
	textures[5] = set_texture(ft_strdup("C"));
	return (textures);
}

static int	free_texture(t_texture *texture)
{
	if (!texture)
		return (0);
	if (texture->name)
		free (texture->name);
	if (texture->dir)
		free (texture->dir);
	if (texture->img)
		free (texture->img);
	return (0);
}

int	free_textures(t_texture **textures)
{
	int		i;

	if (!textures)
		return (0);
	i = -1;
	while(textures[++i])
		if (textures[i])
			free_texture(textures[i]), free (textures[i]);
	return (free (textures), ft_printf_fd(1, "Liberadas texturas\n"), 0);
}

/* 
static t_texture	*return_texture(char *name)
{
	t_texture	*texture;

	texture = (t_texture *)ft_calloc(sizeof(t_texture *), 1);
	if (!ft_strcmp(name, "NO"))
		data->map_textures->t_no = texture;
	else if (!ft_strcmp(name, "SO"))
		data->map_textures->t_so = texture;
	else if (!ft_strcmp(name, "WE"))
		data->map_textures->t_we = texture;
	else if (!ft_strcmp(name, "EA"))
		data->map_textures->t_ea = texture;
	else if (!ft_strcmp(name, "F"))
		data->map_textures->t_f = texture;
	else if (!ft_strcmp(name, "C"))
		data->map_textures->t_c = texture;
	return (texture);
}

int	check_texture(char *texture, char *name)
{
	t_texture	*img;

	if (!texture)
		return (1);
	img = return_texture(name);
	check_image(texture, img);
	if (!img)
		return (1);
	ft_printf ("texture -> %s\n", texture);
	return (0);
}
 */