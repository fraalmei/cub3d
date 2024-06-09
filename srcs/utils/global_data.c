/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:33:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/09 17:37:34 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*init_data(void)
{
	t_game		*data;
	t_size		map;
	t_size		img;

	data = ft_calloc(sizeof(t_game), 1);
	if (!data)
		return (NULL);
	map.height = 100;
	map.width = 100;
	img.height = 100;
	img.width = 100;
	*data->window = new_program(map, img, "cub");
	if (&data->window == NULL)
		return (free(data), NULL);
	return (data);
}

static void	print_map_texture(t_texture *texture)
{
	ft_printf_fd(1, "-----------------------\n");
	if (texture->dir)
		ft_printf_fd(1, "Dir: %s\n", texture->dir);
	if (texture->img)
		ft_printf_fd(1, "img: %s\n", texture->img);
	if (texture->size.height)
		ft_printf_fd(1, "width: %s\n", texture->size.height);
	if (texture->size.width)
		ft_printf_fd(1, "height: %s\n", texture->size.width);
	ft_printf_fd(1, "-----------------------\n");
}


void	print_map_textures(t_textures *textures)
{
	if (textures->t_no->dir)
		print_map_texture (textures->t_no);
	if (textures->t_so->dir)
		print_map_texture (textures->t_so);
	if (textures->t_we->dir)
		print_map_texture (textures->t_we);
	if (textures->t_ea->dir)
		print_map_texture (textures->t_ea);
	if (textures->t_f->dir)
		print_map_texture (textures->t_f);
	if (textures->t_c->dir)
		print_map_texture (textures->t_c);
}

static int	free_map_textures(t_textures *textures)
{
	if (textures->t_no->dir)
		free (textures->t_no->dir);
	if (textures->t_no->img)
		free (textures->t_no->img);
	if (textures->t_so->dir)
		free (textures->t_so->dir);
	if (textures->t_so->img)
		free (textures->t_so->img);
	if (textures->t_we->dir)
		free (textures->t_we->dir);
	if (textures->t_we->img)
		free (textures->t_we->img);
	if (textures->t_ea->dir)
		free (textures->t_ea->dir);
	if (textures->t_ea->img)
		free (textures->t_ea->img);
	if (textures->t_f->dir)
		free (textures->t_f->dir);
	if (textures->t_f->img)
		free (textures->t_f->img);
	if (textures->t_c->dir)
		free (textures->t_c->dir);
	if (textures->t_c->img)
		free (textures->t_c->img);
	return (0);
}

int	free_data(t_game *data)
{
	free_map_textures(data->map_textures);
	free(data->map_textures);
	free(data);
	return (0);
}
