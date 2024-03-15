/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:03:42 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/15 09:08:07 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

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
