/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:12:40 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/17 23:21:47 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*set_texture(char *name)
{
	t_texture	*texture;

	texture = (t_texture *)ft_calloc(sizeof(t_texture), 1);
	texture->name = name;
	texture->dir = NULL;
	texture->png_img = NULL;
	texture->color = -1;
	return (texture);
}

t_texture	**set_textures(void)
{
	t_texture	**textures;

	textures = (t_texture **)ft_calloc(sizeof(t_texture *), 7);
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
	if (texture->png_img)
		mlx_delete_texture (texture->png_img);
	free (texture);
	return (0);
}

int	free_textures(t_texture **textures)
{
	int		i;

	if (!textures)
		return (0);
	i = -1;
	while (textures[++i])
		if (textures[i])
			free_texture(textures[i]);
	free (textures);
	return (0);
}
