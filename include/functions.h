/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/10/11 12:10:01 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <cub3d.h>

/// scrs
	/// parse
		// check_elemensts.c
t_texture	**check_elements(int fd);

		// check_image.c
int			is_color(char *str);
int			check_images(t_texture *texture);

		// check_map
char		**read_map(int fd);

		// check_player
int			get_player_pos(t_game *game);

		// scene
int			check_scene(t_game *game, char *file);

	/// structs
		// global_data.c
t_game		*init_data(void);
int			free_data(t_game *game);
int			print_global(t_game *game);

		// map.c
int			print_map(t_map *map);
int			free_map(t_game *game);
int			set_map(t_game *game, int fd);

		// textures.c
t_texture	**set_textures(void);
int			free_textures(t_texture **texture);
int			print_textures(t_texture **textures);

		// player.c
int			print_player_inf(t_player *player);
int			set_player(t_game *game);

	/// utils

		// matrix_utils.c
int			fill_matrix(char ***matrix, char c);
t_vector2	matrix_len(char **matrix);
//t_size		matrix_len(char **matrix);

		// array_utils.c
char		*del_char_str(char *str, char c);
int			ft_chrcmp_str(char c, char *str);
int			ft_str_arr_cmp(char *str, char **arr);
int			ft_del_str_arr_chr_cmp(char c, char ***arr);
char		**del_node_arr(char **arr, char *str);

		//  file_utils.c
int			check_extension(char *file, char *ext);
int			check_readable(char *file);

		// free.c
int			free_arr(void **arr);

		// set_utils.c
// char		**set_double_arr(char *str, char c);

		// print_things.c
int			print_arr(char **str);
int			print_arr_uint8_t(uint8_t *i);

		// read_utils.c
char		*get_next_notempty_line(int fd);
char		*read_word(char *buffer, int *i);
char		*get_word(char *str, int w);
int			check_empty_line(char *line);

		// print_things
char		*del_char_str(char *str, char c);
char		**del_node_arr(char **arr, char *str);


		// paco_engine
void		engine_check(t_game *game);

#endif
