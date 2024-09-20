/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:44:02 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/20 13:54:55 by cagonzal         ###   ########.fr       */
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
# define FOV 60
# define FOV_RAD ((double)FOV * M_PI / 180.0)  /** FOV in radians */
# define T_SIZE 32
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed
# define EPSILON 0.000001


// Color.c
int		extract_color(t_vector3 color);

// End_program.c
int		end_program(t_game *game);

// Engine.c
t_game	*init(t_game *game);
void	init_color_textures(t_game *game);
void	update(void *g);

// Player_data.c
void	player_data(t_game *game);

// Keys.c
void	read_keys_check(mlx_key_data_t keydata, void *param);
void	read_mouse_check(mouse_key_t button, action_t action, modifier_key_t mods, void *param);

// Ray.c
double	get_h_inter(t_game *game, double angle);
double	get_v_inter(t_game *game, double angle);
void	cast_rays(t_game *game);

void	render_scene(t_game *game, int i);

// Ray_utils.c
float	nor_angle(float angle);
int		unit_circle(float angle, char c);
int		wall_hit(t_game *game, float x, float y);

// Misc_functions.c
// void	image_update(t_game *game);
void	init_ray(t_ray *ray, int ray_index, double ray_angle);
void	esc_function(t_game *game);
void	space_funcion(void);

// Screen_frame.c
int		get_color(t_game *game, t_ray *ray);
void	render_wall(t_game *game, t_ray *ray, int t_pix, int b_pix);
void	render_floor_ceiling(t_game *game, t_ray *ray, int t_pix , int b_pix);

// keys.c
int		read_keys(int key_pressed, void *param);

#endif
