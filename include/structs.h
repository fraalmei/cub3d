/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/14 10:48:49 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3d.h>
# include "../vector/src/vector.h"

typedef struct s_size
{
	size_t		width;
	size_t		height;
}				t_size;

typedef struct s_texture
{
	char				*name;
	char				*dir;
	void				*img;
	struct s_size		size;
}				t_texture;

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

typedef struct s_data
{
	unsigned int	*img;
	char	*addr;
	int		bpp; //bits per pixel
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player
{
	t_vector2	position;
	t_vector2	direction;
}	t_player;

typedef struct s_time
{
	double	time;
	double	old_time;
}	t_time;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_size	size_map;
	struct s_size	size_img;
}				t_win;

typedef struct s_game
{
	t_win					*window;
	t_data					data;
	struct s_texture		*map_textures;
	t_player				player;
	t_vector3				map;
	t_vector2				camera_plane; // perpendicular to dir
	double					fov;
	double					camx;
	t_vector2				ray_dir;
	t_vector2				side_dist; // distance from begin to 1st intersection
	t_vector2				delta_dist; //  distance from one intersection to next
	double					per_wall_dist; // for raylenght calc
	t_vector2				step; // ray direction
}					t_game;

#endif
