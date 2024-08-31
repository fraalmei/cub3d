/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2024/08/29 16:15:38 by p                ###   ########.fr       */
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

typedef struct s_isize
{
	int			width;
	int			height;
}				t_isize;
 
typedef struct s_fsize
{
	float		width;
	float		height;
}			t_fsize;

typedef struct s_texture
{
	char				*name;
	char				*dir;
	void				*img;
	int					color;
	t_vector2			size;
}				t_texture;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_directions
{
	EAST = 0,
	SOUTH = 1,
	WEST = 2,
	NORTH = 3
}	t_directions;

typedef struct s_tilemap
{
	int		pos_x;
	int		pos_y;
	char	value;
}	t_tilemap;

typedef struct s_ray
{
	int			ray;		///< Ray index
	int			flag;		///< Indicator if the ray hit a wall
	double		ray_angle;	///< Angle of the ray
	double		distance;	///< Distance from the player to the wall intersection
	// t_vector2	hit;		///< Position of the wall intersection
	// double		point;		///< Point of impact of the ray on the wall
	// double		wall;		///< Position of the wall hit
	// int			ray_at;		///< Ray index in the context of a raycasting loop
	// bool		hor;		///< Indicator for horizontal intersection
	// bool		ver;		///< Indicator for vertical intersection
	// t_vector2	h;			///< Coordinates of the horizontal intersection
	// t_vector2	step;		///< Incremental step of the ray in the x and y directions
	// t_vector2	v;			///< Coordinates of the vertical intersection
	// t_vector2	map;		///< Coordinates of the map tile the ray is currently in
	// t_vector2	r;			///< Current coordinates of the ray in world space
	// float		dof;		///< Depth of field
	// float		disth;		///< Distance to the nearest horizontal intersection
	// float		distv;		///< Distance to the nearest vertical intersection
}	t_ray;


typedef struct s_mlx
{
	mlx_image_t	*img;
	mlx_t		*p_mlx;
}	t_mlx;

typedef struct s_player
{
	int			init_grid_pos[2];
	t_vector2	pos;		///< Player position
	double		angle;		///< Player angle
	float		fov_rd;		///< Field of view in radians
	int			rot;		///< Rotation flag
	int			l_r;		///< Left-right flag
	int			u_d;		///< Up-down flag
}	t_player;

typedef struct s_image
{
	void	*image;
	char	*add;
	int		width;
	int		height;
	int		endian;
	int		bpp;
	int		length;
}	t_image;

typedef struct s_map
{
	t_texture		**map_textures;
	char			**map;
	t_fsize			tile_size;
	t_vector2		map_size;
//	t_size			map_size;
}			t_map;

typedef struct s_game
{
	t_mlx			mlx;
// 	t_player		player;
	t_player		*player;		// paco engine
	t_ray			*ray;			///< Ray Structure

	t_image			frame;
	t_image			mnmap;
	char			**matrix;

	t_vector2		player_init_pos;		///< Player initial position
	char			player_or;
	int				floor_color;
	int				roof_color;
	int				north_texture;
	int				east_texture;
	int				south_texture;
	int				west_texture;

	t_map			*map;
}					t_game;

#endif
