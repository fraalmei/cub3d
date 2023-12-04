/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2023/11/25 12:28:34 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	leaks(void)
{
	system ("leaks -q cub3D");
}
	//atexit(leaks);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf_fd(2, "Numero de argumentos incorrecto.\n"), 0);
	read_map(argv[1]);
	atexit(leaks);
	return (0);
}
