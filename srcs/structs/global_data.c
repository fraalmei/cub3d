/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:33:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/30 01:31:34 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*init_data(void)
{
	t_game		*data;
	/* t_size		map;
	t_size		img; */

	data = ft_calloc(sizeof(t_game), 1);
	if (!data)
		return (NULL);
	/* map.height = 100;
	map.width = 100;
	img.height = 100;
	img.width = 100; */
/* 	*data->window = new_program(map, img, "cub");
	if (&data->window == NULL)
		return (free(data), NULL); */
	return (data);
}

/* static void	print_map_texture(t_texture *texture)
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
*/
int	free_data(t_game *game)
{
	free_textures(game->map_textures);
	free_arr((void **)game->map);
	free(game);
	return (0);
}
