/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/28 18:22:53 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <cub3d.h>

/// scrs
	/// parse
		// scene
int			check_scene(t_game *game, char *file);
		// check_elements.c
t_texture	**check_elements(int fd);
		// check_image.c
int			is_color(char *str);
		// check_textures.c
t_texture	**set_textures(void);
int			free_textures(t_texture **texture);
		// map
char		**read_map(int fd);

	/// utils
		//  file_utils.c
int		check_extension(char *file, char *ext);
int		check_readable(char *file);
		// utils.c
char	**set_double_arr(char *str, char c);
char	*del_char_str(char *str, char c);
int		print_arr(char **str);
char	*read_word(char *buffer, int *i);
char	*get_word(char *str, int w);
char	*get_next_notempty_line(int fd);
int		ft_chrcmp_str(char c, char *str);
int		ft_str_arr_cmp(char *str, char **arr);
int		ft_del_str_arr_chr_cmp(char c, char ***arr);
int		check_empty_line(char *line);
		// free.c
int		free_arr(void **arr);
//char	**create_array(char *line);
char	**del_node_arr(char **arr, char *str);
		// global_data
t_game	*init_data(void);
// void	print_map_textures(t_textures *map_textures);
// int		free_data(t_game *data);
		// print_things
int 	print_textures(t_texture **textures);

	//engine
void	engine(void);

	// window
		// window
//t_win	new_program(t_size map, t_size img, char *str);

#endif
