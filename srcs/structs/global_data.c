/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:33:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/08/05 17:48:59 by p                ###   ########.fr       */
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
	ft_printf_fd (1, COLOR_YELLOW);
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd(1, "################### FREEING GAME ###################\n");
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, COLOR_RESET);
	free_map(game);
	ft_printf_fd(1, "Map freed.\n");
	free(game->player);
	ft_printf_fd(1, "Player freed.\n");
	free(game);
	ft_printf_fd (1, COLOR_YELLOW);
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd(1, "#################### GAME FREED ####################\n");
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, COLOR_RESET);
	return (0);
}

int	print_global(t_game *game)
{
	ft_printf_fd (1, COLOR_YELLOW);
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, "################## PRINTING DATA ##################\n");
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, COLOR_RESET);
	if (game->map)
		print_map(game->map);
	if(game->player)
		print_player_inf(game->player);
	ft_printf_fd (1, COLOR_YELLOW);
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, "################### DATA PRINTED ##################\n");
	ft_printf_fd (1, "###################################################\n");
	ft_printf_fd (1, COLOR_RESET);
	return (0);
}
