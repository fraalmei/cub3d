/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/17 12:42:27 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3d.h>

typedef struct s_size
{
	size_t		width;
	size_t		height;
}				t_size;
/* 
typedef enum e_directions
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}	t_directions;

typedef struct s_tile
{
	void *tect[4];
	struct t_tile no;
	struct t_tile so;
	struct t_tile we;
	struct t_tile ea;
}	t_tile;


	t_vector3 floor;
	t_vector3 ceiling;
tile[X][Y];

 *tex[NORTH];
 *tex[SOUTH];
 *tex[WEST];
 *tex[EAST];


floor.r = 220
floor.g = 100
floor.b = 0
 */

#endif
