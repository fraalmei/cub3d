/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:12:40 by p                 #+#    #+#             */
/*   Updated: 2024/09/01 17:07:11 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void	leaks(void)
{
	system("leaks -q cub3d");
}
	//atexit(leaks);

int	main(int argc, char **argv)
{
	t_game		*game;

	atexit(leaks);
	if (argc != 2)
		return (ft_printf_fd(2, "Number of arguments wrong %d.\n", \
			argc - 1), 0);
	game = init_data();
	if (check_scene(game, argv[1]))
		return (ft_printf_fd(2, "Map error.\n"),1);
	print_global(game);
	engine_check(game);
	free_data(game);
	return (0);
}

/* int main(void)
{
    mlx_t *mlx_ptr;         // Puntero para la conexión a la sesión de la ventana
    mlx_image_t *img_ptr;   // Puntero para la imagen

    // Inicializar la conexión con el servidor gráfico y crear la ventana
    mlx_ptr = mlx_init(800, 600, "Ventana MLX", 1);
    if (mlx_ptr == NULL)
    {
        return (EXIT_FAILURE);
    }

    // Cargar una textura desde un archivo PNG
    mlx_texture_t *texture = mlx_load_png("./assets/textures/girl_with_a_pearl_earring.png");
    if (texture == NULL)
    {
        mlx_terminate(mlx_ptr);
        return (EXIT_FAILURE);
    }

    // Convertir la textura cargada en una imagen de MLX
    img_ptr = mlx_texture_to_image(mlx_ptr, texture);
    if (img_ptr == NULL)
    {
        mlx_delete_texture(texture); // Liberar la textura si la conversión falla
        mlx_terminate(mlx_ptr);
        return (EXIT_FAILURE);
    }

    // Liberar la textura después de convertirla a una imagen de MLX
    mlx_delete_texture(texture);

    // Mostrar la imagen en la ventana en la posición (0, 0)
    if (mlx_image_to_window(mlx_ptr, img_ptr, 0, 0) < 0)
    {
        mlx_delete_image(mlx_ptr, img_ptr); // Liberar la imagen si falla la operación
        mlx_terminate(mlx_ptr);
        return (EXIT_FAILURE);
    }

    // Bucle de eventos
    mlx_loop(mlx_ptr);

    // Liberar recursos (aunque el bucle de eventos es infinito, se incluye para buenas prácticas)
    mlx_close_window(mlx_ptr);
    mlx_terminate(mlx_ptr);

    return (EXIT_SUCCESS);
} */
