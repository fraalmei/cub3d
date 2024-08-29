/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check_image.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: fraalmei <fraalmei@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/27 16:06:15 by fraalmei		  #+#	#+#			 */
/*   Updated: 2023/12/04 13:00:03 by fraalmei		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

/// @brief checking if is a texture or a solid color
/// @param str 
/// @return a 0 if its a color or1 if not
int	is_color(char *str)
{
	int		i;
	int		l;
	int		num;
	char	**swap;

	swap = ft_split(str, ',');
	if (!swap[2] || !swap[1])
		return (free_arr((void **)swap), 1);
	i = -1;
	while (swap[++i] && i < 4)
	{
		l = -1;
		while (swap[i][++l])
			if (!(swap[i][l] >= 48 && swap[i][l] <= 57))
				return (1);
		num = ft_atoi(swap[i]);
		if (!(num >= 0 && num <= 255))
			return (free_arr((void **)swap), 1);
	}
	free_arr((void **)swap);
	return (0);
}

int	get_rgba(char *color)
{
	int		i;
	int		ret;
	char	**colors;

	i = 255;
	colors = ft_split(color, ',');
	if (!colors)
		return (-1);
	if (colors[3])
		i = ft_atoi(colors[3]);
	ret = (ft_atoi(colors[0]) << 24) | (ft_atoi(colors[1]) << 16) \
		| (ft_atoi(colors[2]) << 8) | (i);
	free_arr((void **) colors);
	return (ret);
}

int	check_images(t_game *game)
{
	int		i;

	i = -1;
	while (game->map->map_textures[++i])
	{
		if (check_extension(game->map->map_textures[i]->dir, ".png"))
			game->map->map_textures[i]->img = mlx_load_png(game->map->map_textures[i]->dir);
		else if (check_extension(game->map->map_textures[i]->dir, ".xpm"))
			game->map->map_textures[i]->img = mlx_load_xpm42(game->map->map_textures[i]->dir);
		else if (is_color(game->map->map_textures[i]->dir))
			game->map->map_textures[i]->color = get_rgba(game->map->map_textures[i]->dir);
		else
			return (1);
	}
	return (0);
}
