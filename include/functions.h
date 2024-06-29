/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/28 14:36:07 by cagonzal         ###   ########.fr       */
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
int		check_elements(int fd);
		// images
int		check_image(char *dir);
		// map
//int		check_map(char *map);

	/// utils
		//  file_utils.c
int		check_extension(char *file, char *ext);
int		check_readable(char *file);
		// utils.c
char	*del_char_str(char *str, char c);
//char	**create_array(char *line);
char	**del_node_arr(char **arr, char *str);

	//engine
void	engine(t_game game);

#endif
