/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:06:24 by fraalmei          #+#    #+#             */
/*   Updated: 2024/10/28 10:48:43 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <math.h>

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/include/libft.h"

# include "../vector/src/vector.h"

# include "structs.h"
# include "engine.h"
# include "key_linux.h"
# include "keys.h"
# include "functions.h"
# include "color.h"

#define PRINT_FPS	PRINT_DEBUG("Frames = %d", game->n_frame);
#define PRINT_POS	PRINT_DEBUG("Player pos[%d][%d]", (int)floor(game->player->pos.x), (int)floor(game->player->pos.y));
#define PRINT_ROT	PRINT_DEBUG("Player_rot in degrees = %d", (int)floor(game->player->angle * 180 / M_PI));

#endif
