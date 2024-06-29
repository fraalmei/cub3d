/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:54:52 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/29 13:29:57 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	print_textures(t_texture **textures)
{
	int		i;

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
		if (textures[i]->img)
			ft_printf_fd(1, "Img: OK\n");
		if (textures[i]->size.width)
			ft_printf_fd(1, "Width: %d\n", textures[i]->size.width);
		if (textures[i]->size.height)
			ft_printf_fd(1, "Height: %d\n", textures[i]->size.height);
		ft_printf_fd(1, "########################################\n");
	}
	return (0);
}

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

int	print_global(t_game *game)
{
	ft_printf_fd (1, " - Texturas - \n");
	print_textures (game->map_textures);
	ft_printf_fd (1, " - Mapa - \n");
	print_arr(game->map);
	return (0);
}
