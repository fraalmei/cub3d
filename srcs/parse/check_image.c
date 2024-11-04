/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:26:35 by p                 #+#    #+#             */
/*   Updated: 2024/11/04 12:11:48 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief checking if is a texture or a solid color
/// @param str 
/// @return a 0 if its a color or1 if not
int	is_color(char *str)
{
	char	**rgba;

	ft_printf_fd(1, "Checking if it's a color\n");
	rgba = ft_split(str, ',');
	if (ft_str_arraylen(rgba) < 3 || ft_str_arraylen(rgba) > 4)
		return (ft_printf_fd(1, "Error data color\n"), \
			free_arr_string(rgba), 1);
	if (!(ft_atoi(rgba[0]) >= 0 && ft_atoi(rgba[0]) <= 255 && \
			ft_atoi(rgba[1]) >= 0 && ft_atoi(rgba[1]) <= 255 && \
			ft_atoi(rgba[2]) >= 0 && ft_atoi(rgba[2]) <= 255))
		return (ft_printf_fd(1, "Incorrect data rank\n"), \
			free_arr_string(rgba), 1);
	if (rgba[3])
		if (!(ft_atoi(rgba[3]) >= 0 && ft_atoi(rgba[3]) <= 255))
			return (ft_printf_fd(1, "Incorrect alpha rank\n"), \
				free_arr_string(rgba), 1);
	free_arr_string(rgba);
	ft_printf_fd(1, "It's a color\n");
	return (0);
}

static unsigned int	get_rgba(char *color)
{
	int					i;
	long				ret;
	char				**colors;

	ft_printf_fd(1, "Entra get_rgba");
	i = 255;
	colors = ft_split(color, ',');
	if (!colors)
		return (0);
	if (colors[3])
		i = ft_atoi(colors[3]);
	ft_printf_fd(1, "Entra get_rgba %s\n", color);
	ft_printf_fd(1, "string R = %s\nstring G = %s\nstring B = %s\nA = %d\n", \
		colors[0], colors[1], colors[2], i);
	ft_printf_fd(1, "int R = %d\nint G = %d\nint B = %d\nint A = %d\n", \
		ft_atoi(colors[0]), ft_atoi(colors[1]), ft_atoi(colors[2]), i);
	ret = (ft_atoi(colors[0]) << 24) | (ft_atoi(colors[1]) << 16) \
		| (ft_atoi(colors[2]) << 8) | (i);
	ft_printf_fd(1, "RGBA obtenido: %u\n", ret);
	free_arr_string(colors);
	return (ret);
}

int	check_images(t_texture *texture)
{
	if (!check_extension(texture->dir, ".png"))
	{
		texture->png_img = mlx_load_png(texture->dir);
		if (!texture->png_img)
			return (ft_printf_fd(2, "Fallo cargando imagen %s\n", \
				texture->dir), 1);
	}
	else if (is_color(texture->dir) == 0)
	{
		texture->color = get_rgba(texture->dir);
		if (!texture->color)
			return (ft_printf_fd(2, "Fallo cargando color\n"), 1);
	}
	else
		return (ft_printf_fd(1, "Error obteniendo imagen / color\n"));
	return (0);
}
