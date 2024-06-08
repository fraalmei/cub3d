/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/08 16:05:53 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <cub3d.h>

/// scrs
	/// parse
		// scene
int		check_scene(char *file);
		// elements
			// check_elements.c
int		check_elements(int fd);
			// check_image.c
int		check_image(char *dir, t_texture *img);
			// check_textures.c
int		check_texture(char *texture, char *name);
		// map
//int		check_map(char *map);

	/// utils
		//  file_utils.c
int		check_extension(char *file, char *ext);
int		check_readable(char *file);
		// utils.c
char	*del_char_str(char *str, char c);
int		print_arr(char **str);
char	*read_word(char *buffer, int *i);
char	*get_word(char *str, int w);
char	*get_next_notempty_line(int fd);
		// free.c
int		free_arr(void **arr);
//char	**create_array(char *line);
char	**del_node_arr(char **arr, char *str);
		// global_data
void	print_map_textures(void);
int		free_data(void);

	//engine
void	engine(void);

#endif
