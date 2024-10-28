/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:44:02 by cagonzal          #+#    #+#             */
/*   Updated: 2024/10/28 10:55:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <cub3d.h>

# define S_WIDTH 1200 /**< Ancho de la pantalla */
# define S_HEIGHT 800 /** Alto de la pantalla */

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

// Convierte el ángulo de visión de grados a radianes
# define FOV 60 /**< Field of view */
# define FOV_RAD ((double)FOV * M_PI / 180.0)  /** FOV in radians */
# define T_SIZE 64 /**< Tile size */
# define CENTER (T_SIZE / 2) /**< Center of the tile */
# define ROTATION_SPEED 0.02 /**< Rotation speed */
# define PLAYER_SPEED 2 /**< Player speed */
# define EPSILON 0.000001 /**< Epsilon */

// End_program.c
void	end_program(void *g);

// Engine.c
void	update(void *g);
void	frame_counter(t_game *game);
void	engine(t_game *game);

// Input.c
void	hook(t_game *game);
void	rotate_player(t_game *game, int rot);
void	move_player(t_game *game, double move_x, double move_y);

// Keys.c
void	read_keys_check(mlx_key_data_t keydata, void *param);
void	key_release(mlx_key_data_t keydata, t_game *game);
void	player_rotate(t_game *game);

// Ray_casting.c
int		inter_check(double angle, float *inter, float *step, int is_horizon);
int		wall_hit(t_game *game, double x, double y);
double	get_h_inter(t_game *game, t_ray *ray, double angl);
double	get_v_inter(t_game *game, t_ray *ray, double angl);
void	cast_rays(t_game *game);

// Ray_utils.c
float	nor_angle(float angle);
int		unit_circle(float angle, char c);
double	get_x_o(t_game *game, t_ray *ray, mlx_texture_t *texture);
int     reverse_bytes(int c);

// Screen_frame.c
mlx_texture_t*	get_side_texture(t_game *game, t_ray *ray);
void			render_wall(t_game *game, t_ray *ray, double t_p , double b_p, double w_h);
void			render_floor_ceiling(t_game *game, t_ray *ray, double t_pix , double b_pix);
void			render_scene(t_game *game, t_ray *ray);

#endif
