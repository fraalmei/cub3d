/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:34:09 by cagonzal          #+#    #+#             */
/*   Updated: 2024/10/03 13:41:33 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

#include "structs.h"

void frame_counter(t_game *game)
{
	game->n_frame++;
	if (game->n_frame++ < 60)
		game->n_frame = 0;
	// PRINT_DEBUG("Function %s: Frame %d : G_Frames: %d\r", __func__, game->n_frame, game->n_g_frames);
}