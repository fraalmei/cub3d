/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:12:40 by fraalmei          #+#    #+#             */
/*   Updated: 2024/10/21 15:33:55 by p                ###   ########.fr       */
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
	texture->xpm_img = NULL;
	texture->png_xmp = 0;
	texture->color = -1;
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
	if (texture->png_img)
		free (texture->png_img);
	if (texture->xpm_img)
		free (texture->xpm_img);
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
			(free_texture(textures[i]), free (textures[i]));
	return (free (textures), ft_printf_fd(1, "Textures freed.\n"), 0);
}

int	print_textures(t_texture **textures)
{
	int		i;

	ft_printf_fd(1, "Name:\n");
	if (!textures)
		return (0);
	i = -1;
	while (textures[++i])
	{
		if (textures[i]->name)
			ft_printf_fd(1, "Name: %s\n", textures[i]->name);
		if (textures[i]->dir)
		{
			ft_printf_fd(1, "Dir: %s\n", textures[i]->dir);
			ft_printf_fd(1, "Img?: %d\n", is_color(textures[i]->dir));
		}
		if (textures[i]->png_img)
		{
			ft_printf_fd(1, "Img png: %p\n", textures[i]->png_img);
			ft_printf_fd(1, "Width: %d\n", textures[i]->png_img->width);
			ft_printf_fd(1, "Height: %d\n", textures[i]->png_img->height);
			ft_printf_fd(2, "Bytes_per_pixel: %d\n", textures[i]->png_img->bytes_per_pixel);
			//sft_printf_fd(2, "Pixels: ");
			//print_arr_uint8_t(textures[i]->png_img->pixels);
		}
		else if (textures[i]->color != 0)
			ft_printf_fd(1, "Color: %u\n", textures[i]->color);
		ft_printf_fd (1, COLOR_CYAN);
		ft_printf_fd (1, "###########################################\n");
		ft_printf_fd (1, COLOR_RESET);
	}
	return (0);
}
