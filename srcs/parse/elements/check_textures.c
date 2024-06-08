/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:12:40 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/08 17:01:47 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*return_texture(char *name)
{
	t_texture	*texture;

	texture = (t_texture *)ft_calloc(sizeof(t_texture *), 1);
	if (!ft_strcmp(name, "NO"))
		g_data->map_textures.t_no = texture;
	else if (!ft_strcmp(name, "SO"))
		g_data->map_textures.t_so = texture;
	else if (!ft_strcmp(name, "WE"))
		g_data->map_textures.t_we = texture;
	else if (!ft_strcmp(name, "EA"))
		g_data->map_textures.t_ea = texture;
	else if (!ft_strcmp(name, "F"))
		g_data->map_textures.t_f = texture;
	else if (!ft_strcmp(name, "C"))
		g_data->map_textures.t_c = texture;
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
