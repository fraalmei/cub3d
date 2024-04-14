/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:18:51 by cagonzal          #+#    #+#             */
/*   Updated: 2024/04/14 16:39:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/engine.h"
#include <time.h>

static void apply_rotation(t_vector3 *vertex, float angle_x, float angle_y, float angle_z)
{
	// Aplicar rotación en los ejes X, Y y Z
	float x = vertex->x;
	float y = vertex->y;
	float z = vertex->z;

	// Rotación en el eje X
	float new_y = y * cos(angle_x) - z * sin(angle_x);
	float new_z = y * sin(angle_x) + z * cos(angle_x);
	y = new_y;
	z = new_z;

	// Rotación en el eje Y
	float new_x = x * cos(angle_y) + z * sin(angle_y);
	new_z = -x * sin(angle_y) + z * cos(angle_y);
	x = new_x;
	z = new_z;

	// Rotación en el eje Z
	new_x = x * cos(angle_z) - y * sin(angle_z);
	new_y = x * sin(angle_z) + y * cos(angle_z);
	x = new_x;
	y = new_y;

	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
}

static void draw_3d_scene(void *mlx_ptr, void *win_ptr)
{
	t_vector3 vertices[] =
	{
		ft_vector3(-50, -50, -50),
		ft_vector3(50, -50, -50),
		ft_vector3(-50, 50, -50),
		ft_vector3(-50, -50, 50),
		ft_vector3(50, 50, -50),
		ft_vector3(50, -50, 50),
		ft_vector3(-50, 50, 50),
		ft_vector3(50, 50, 50)
	};

	// Aplicar una rotación al cubo en la escena 3D
	float angle_x = 0.5;
	float angle_y = 0.3;
	float angle_z = 0.2;

	for (int i = 0; i < 8; i++)
	{
		apply_rotation(&vertices[i], angle_x, angle_y, angle_z);
		// Proyectar y dibujar cada vértice rotado en la ventana 2D
		// (Implementación similar a los pasos anteriores)
	}
}

// Función para dibujar unlínea en la ventana
// static void draw_line(void *mlx_ptr, void *win_ptr, t_vector32 start, t_vector32 end, int color)
// {
// 	int dx;
// 	int dy;
// 	int sx;
// 	int sy;
// 	int err, e2;

// 	dx =  fabs(end.x - start.x);
// 	dy = -fabs(end.y - start.y);
// 	sx = (start.x < end.x) - (start.x >= end.x);
// 	sy = (start.y < end.y) - (start.y >= end.y);
// 	err = dx + dy; /* error value e_xy */



// 	while (1)
// 	{
// 		mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, color);
// 		if (start.x == end.x && start.y == end.y)
// 			break;
// 		e2 = 2*err;
// 		if (e2 >= dy)
// 		{
// 			err += dy;
// 			start.x += sx;
// 		} /* e_xy+e_x > 0 */
// 		if (e2 <= dx)
// 		{
// 			err += dx;
// 			start.y += sy;
// 		} /* e_xy+e_y < 0 */
// 	}
// }

// Algoritmo de Recursive Backtracking para generar el laberinto
void	generate_map(t_game game)
{
	// Dibujar un mapa básico
	// t_vector32 start = ft_vector32(100, 100); // Tamaño de cada celda del mapa
	// t_vector32 end = ft_vector32(400, 300); // Posición inicial del mapa

	// draw_line(game.mlx, game.window, start, end, 0xFF0000);
	draw_3d_scene(game.mlx, game.window);

}
