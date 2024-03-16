/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:44:02 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/16 22:26:03 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

typedef struct s_data
{
	void	*img;
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

typedef struct s_game
{
	t_player	player;
	t_vector3	map;
	t_vector2	camera_plane; // perpendicular to dir
	double		fov;
	double		camx;
	t_vector2	ray_dir;
	t_vector2	side_dist; // distance from begin to 1st intersection
	t_vector2	delta_dist; //  distance from one intersection to next
	double		per_wall_dist; // for raylenght calc
	t_vector2	step; // ray direction
}	t_game;


void	engine(void);

#endif
