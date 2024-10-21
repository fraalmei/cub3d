/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2024/10/21 09:03:30 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3d.h>

typedef struct s_size
{
	size_t		width;			///< Width of the size
	size_t		height;			///< Height of the size
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
	char				*name;		///< Name of the texture
	char				*dir;		///< Directory of the texture
	mlx_texture_t		*png_img;	///< PNG image pointer
	xpm_t				*xpm_img;	///< XPM image pointer
	int					png_xmp;	///< Indicator if the texture is PNG or XPM
	int					color;		///< Color of the texture
	t_vector2			size;		///< Size of the texture
}				t_texture;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_directions
{
	NORTH = 0,	///< North direction
	SOUTH = 1,	///< South direction
	EAST = 2,    ///< East direction
	WEST = 3		///< West direction
}	t_directions;

typedef struct s_tilemap
{
	int		pos_x;		///< X position of the tile
	int		pos_y;		///< Y position of the tile
	char	value;		///< Value of the tile
}	t_tilemap;

typedef struct s_ray
{
	int			ray;			///< Ray index
	int			hit;			///< Indicator if the ray hit a wall
	int			side;			///< Indicator for the side of the wall hit
	double		ray_angle;		///< Angle of the ray
	double		dist;			///< Distance from the player to the wall intersection
	t_vector2	ray_hor;		///< Horizontal intersection point
	t_vector2	ray_ver;		///< Vertical intersection point
	t_vector2	ray_dir;		///< Direction of the ray
	t_vector2	delta_dist;		///< Distance between the x and y intersections
	t_vector2	step;			///< Step size for the ray
	t_vector2	side_dist;		///< Distance to the next x or y intersection
}	t_ray;


typedef struct s_mlx
{
	mlx_image_t	*img;			///< Image pointer
	mlx_t		*p_mlx;			///< MLX pointer
}	t_mlx;

typedef struct s_player
{
	int			init_grid_pos[2];	///< Initial grid position
	t_vector2	pos;				///< Player position
	double		angle;				///< Player angle
	float		fov_rd;				///< Field of view in radians
	int			rot;				///< Rotation flag
	int			l_r;				///< Left-right flag
	int			u_d;				///< Up-down flag
}	t_player;

typedef struct s_image
{
	void	*image;		///< Image pointer
	char	*add;		///< Image address
	int		width;		///< Image width
	int		height;		///< Image height
	int		endian;		///< Endian
	int		bpp;		///< Bits per pixel
	int		length;		///< Length
}	t_image;

typedef struct s_map
{
	t_texture		**map_textures;		///< Map textures
	char			**map;				///< Map matrix
	t_fsize			tile_size;			///< Tile size
	t_vector2		map_size;			///< Map size
}	t_map;

typedef struct s_game
{
	t_mlx			mlx;				///< MLX Structure
	t_player		*player;			///< Player Structure
	t_ray			*ray;				///< Ray Structure
	t_map			*map;				///< Map structure

	t_image			frame;				///< Frame image
	t_image			mnmap;				///< Minimap image
	char			**matrix;			///< Matrix of the map

	t_vector2		player_init_pos;	///< Player initial position
	char			player_or;			///< Player orientation
	int				floor_color;		///< Floor color
	int				roof_color;			///< Roof color
	int				north_texture;		///< North texture
	int				east_texture;		///< East texture
	int				south_texture;		///< South texture
	int				west_texture;		///< West texture

	int				n_frame;			///< Number of frames
	int				n_g_frames; 		///< Number of grouped frames
	int				n_ray;				///< Number of rays

}	t_game;

#endif
