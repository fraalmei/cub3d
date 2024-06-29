/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/28 14:29:23 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3d.h>
# include "../vector/src/vector.h"

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
	void	*p_mlx;
	void	*window;
	// t_image	*img;
}	t_mlx;

typedef struct s_player
{
	t_vector2	pos;		///< Player position
	double		angle;		///< Player angle
	float		fov_rd;		///< Field of view in radians
	int			rot;		///< Rotation flag
	int			l_r;		///< Left-right flag
	int			u_d;		///< Up-down flag
}	t_player;

typedef struct s_texture
{
	void		*img;
	char		*name;
	char		*dir;
	t_vector2	size;
}	t_texture;

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

typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_vector2	map_size;		///< Map size
	t_vector2	player_pos;		///< Player initial position
	t_ray		*ray;			///< Ray Structure
	t_image		frame;
	t_image		mnmap;
	char		**matrix;
	int			floor_color;
	int			roof_color;
	int			north_texture;
	int			east_texture;
	int			south_texture;
	int			west_texture;
	t_texture	texture[4];
	// char		*north_texture;
	// char		*east_texture;
	// char		*south_texture;
	// char		*west_texture;
}	t_game;

#endif
