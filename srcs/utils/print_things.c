/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:54:52 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/04 15:03:32 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/// @brief print an array of strings
/// @param str 
/// @return the string printed
int	print_arr(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		ft_printf_fd (1, "%s\n", str[i]);
		i++;
	}
	return (i);
}

int	print_arr_uint8_t(uint8_t *i)
{
	int	l;

	if (!i)
		return (1);
	l = 0;
	while (i[l])
	{
		printf("%d ", i[l]);
		l++;
	}
	printf("\n");
	return (0);
}

int	print_textures(t_texture **textures)
{
	int		i;

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
			ft_printf_fd(2, "Bytes_per_pixel: %d\n", \
				textures[i]->png_img->bytes_per_pixel);
		}
		else if (textures[i]->color != 0)
			ft_printf_fd(1, "Color: %u\n", textures[i]->color);
		ft_printf_fd (1, COLOR_CYAN"#########################\n" \
			COLOR_RESET);
	}
	return (0);
}
