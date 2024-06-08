/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:33:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/08 16:32:52 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	init_data(void)
{
	//g_data.map_textures = (t_game *)ft_calloc(sizeof(t_game), 1);
	return (0);
}

static void	print_map_textures(t_texture *texture)
{
	if (texture->dir)
		ft_printf_fd(1, "Dir: %s\n", texture->dir);
	if (texture->img)
		ft_printf_fd(1, "img: %s\n", texture->img);
	if (texture->size.height)
		ft_printf_fd(1, "width: %s\n", texture->size.height);
	if (texture->size.width)
		ft_printf_fd(1, "height: %s\n", texture->size.width);
}


void	print_map_textures(void)
{
	if (g_data.map_textures.t_no.dir)
		print_map_textures (g_data.map_textures.t_no);
	if (g_data.map_textures.t_so.dir)
		print_map_textures (g_data.map_textures.t_so);
	if (g_data.map_textures.t_we.dir)
		print_map_textures (g_data.map_textures.t_we);
	if (g_data.map_textures.t_ea.dir)
		print_map_textures (g_data.map_textures.t_ea);
	if (g_data.map_textures.t_f.dir)
		print_map_textures (g_data.map_textures.t_f);
	if (g_data.map_textures.t_c.dir)
		print_map_textures (g_data.map_textures.t_c);
}

static int	free_map_textures(void)
{
	if (g_data.map_textures.t_no.dir)
		free (g_data.map_textures.t_no.dir);
	if (g_data.map_textures.t_no.img)
		free (g_data.map_textures.t_no.img);
	if (g_data.map_textures.t_so.dir)
		free (g_data.map_textures.t_so.dir);
	if (g_data.map_textures.t_so.img)
		free (g_data.map_textures.t_so.img);
	if (g_data.map_textures.t_we.dir)
		free (g_data.map_textures.t_we.dir);
	if (g_data.map_textures.t_we.img)
		free (g_data.map_textures.t_we.img);
	if (g_data.map_textures.t_ea.dir)
		free (g_data.map_textures.t_ea.dir);
	if (g_data.map_textures.t_ea.img)
		free (g_data.map_textures.t_ea.img);
	if (g_data.map_textures.t_f.dir)
		free (g_data.map_textures.t_f.dir);
	if (g_data.map_textures.t_f.img)
		free (g_data.map_textures.t_f.img);
	if (g_data.map_textures.t_c.dir)
		free (g_data.map_textures.t_c.dir);
	if (g_data.map_textures.t_c.img)
		free (g_data.map_textures.t_c.img);
	return (0);
}

int	free_data(void)
{
	free_map_textures();
	free(g_data);
	return (0);
}
