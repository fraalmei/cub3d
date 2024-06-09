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

	// function to calculate the size of an image
static t_size	count_image_size(int i, int file, t_size size)
{
	char	*line;

	line = get_next_line(file);
	while (line)
	{
		if (ft_strncmp(line, "/* pixels */", 12) == 0 && i == -1)
			i = 0;
		else if (ft_strncmp(line, "};", 2) > -1 && i == 0)
		{
			i = -1;
			free (line);
			return (size);
		}
		else if (i == 0)
		{
			if (ft_strlen(line) - 4 > size.width)
				size.width = ft_strlen(line) - 4;
			size.height++;
		}
		line = (free (line), get_next_line(file));
	}
	free (line);
	return (size);
}

	// open the .xmp files and detect the pixels
static int	detect_image_size(char *dir, t_size *size)
{
	int		file;
	int		i;

	i = -1;
	size->width = 0;
	size->height = 0;
	file = open(dir, O_RDONLY);
	if (file == -1)
		return (1);
	*size = count_image_size(i, file, *size);
	close (file);
	return (0);
}

/*
	// travel all visible characters to detect all files
	// and detect the  maximun size between them
t_size	higher_size_assets(void)
{
	t_size	size;data
	c = 32;
	size.width = 0;
	size.height = 0;
	while (c < 126)
	{
		if (check_map_image(c))
			size_swap = detect_image_size(check_map_image(c));
		else if (check_object_image(c))
			size_swap = detect_image_size(check_object_image(c));
		if (size_swap.width > size.width)
			size.width = size_swap.width;
		if (size_swap.height > size.height)
			size.height = size_swap.height;
		c++;
	}
	return (size);
} */

int	check_image(t_game *data, char *dir, t_texture *img)
{
	img->dir = dir;
	if (check_extension(dir, ".xpm"))
		return (ft_printf("Error: extension\n"), 1);
	detect_image_size(dir, &img->size);
	/* img->img = mlx_xpm_file_to_image(g_data->window->mlx_ptr, dir, \
		(int *)img->size.width, (int *)img->size.height);
	if (!img->img)
		return (1); */
	print_map_textures(data->map_textures);
	return (0);
}
