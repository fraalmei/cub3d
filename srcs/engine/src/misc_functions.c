/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:34:09 by cagonzal          #+#    #+#             */
/*   Updated: 2024/09/30 14:55:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

#include "structs.h"

void frame_counter(t_game *game)
{
    if (game->n_frame < 20)
    {
        if (game->n_ray < S_WIDTH)
            game->n_ray += S_WIDTH / 20;
        game->n_frame++;
    }
    else if (game->n_frame++ < 60)
    {
        game->n_frame = 0;
        game->n_g_frames++;
    }
    if (game->n_g_frames >= 10)
    {
        game->n_ray = 0;
        game->n_g_frames = 0;
    }
    PRINT_DEBUG("Function %s: Frame %d : G_Frames: %d\r", __func__, game->n_frame, game->n_g_frames);
}