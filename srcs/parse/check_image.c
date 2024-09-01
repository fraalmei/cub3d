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
	char	**rgba;

	ft_printf_fd(1, "Comprobando si es color\n");
	rgba = ft_split(str, ',');
	if (ft_arraylen((const void **)rgba) < 3 || ft_arraylen((const void **)rgba) > 4)
		return (ft_printf_fd(1, "Error cantidad datos de color\n"), free_arr((void **)rgba), 1);
	if (!(ft_atoi(rgba[0]) >= 0 && ft_atoi(rgba[0]) <= 255 && ft_atoi(rgba[1]) >= 0  && \
			ft_atoi(rgba[1]) <= 255 && ft_atoi(rgba[2]) >= 0 && ft_atoi(rgba[2]) <= 255))
		return (ft_printf_fd(1, "Rango de color incorrecto\n"), free_arr((void **)rgba), 1);
	if (rgba[3])
		if (!(ft_atoi(rgba[3]) >= 0 && ft_atoi(rgba[3]) <= 255))
			return (ft_printf_fd(1, "Rango alfa incorrecto\n"), free_arr((void **)rgba), 1);
	free_arr((void **)rgba);
	ft_printf_fd(1, "Es color\n");
	return (0);
}

/* unsigned int	get_rgba(char *color)
{
	int					i;
	long		ret;
	char				**colors;

	i = 255;
	colors = ft_split(color, ',');
	if (!colors)
		return (-1);
	if (colors[3])
		i = ft_atoi(colors[3]);
	ret = (ft_atoi(colors[0]) << 24) | (ft_atoi(colors[1]) << 16) \
		| (ft_atoi(colors[2]) << 8) | (i);
	free_arr((void **) colors);
	ft_printf_fd(1, "RGBA obtenido: %d\n", ret);
	return (ret);
} */

static int	get_rgba(char *color)
{
	int					i;
	long				ret;
	char				**colors;

	i = 255;
	colors = ft_split(color, ',');
	if (!colors)
		return (0);
	if (colors[3])
		i = ft_atoi(colors[3]);
	ret = (ft_atoi(colors[0]) << 24) | (ft_atoi(colors[1]) << 16) \
		| (ft_atoi(colors[2]) << 8) | (i);
	ft_printf_fd(1, "RGBA obtenido: %d\n", ret);
	return (ret);
}

int	check_images(t_texture *texture)
{
	if (!check_extension(texture->dir, ".png"))
	{
		texture->png_img = mlx_load_png(texture->dir);
		if (!texture->png_img)
			return (ft_printf_fd(2, "Fallo cargando imagen %s\n", texture->dir), 1);
	}
	else if (!check_extension(texture->dir, ".xpm"))
	{
		texture->xpm_img = mlx_load_xpm42(texture->dir);
		if (!texture->xpm_img)
			return (ft_printf_fd(2, "Fallo cargando imagen %s\n", texture->dir), 1);
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
