/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:37:58 by fraalmei          #+#    #+#             */
/*   Updated: 2024/08/26 10:28:40 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

int	read_keys(int key_pressed, void *param)
{
	t_game			*data;

	data = (t_game *)param;
	if (key_pressed == K_ESC || !data->mlx.p_mlx)
		end_program(data);
	return (0);
}
