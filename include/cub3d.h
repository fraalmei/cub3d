/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:06:24 by fraalmei          #+#    #+#             */
/*   Updated: 2024/08/22 09:24:41 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


// # include <mlx.h>
# include <MLX42.h>

# include <vector.h>
# include "../libft/include/libft.h"

# include "structs.h"
# include "engine.h"
# include "key_linux.h"
# include "keys.h"
# include "functions.h"
# include "color.h"

#define PRINT_DEBUG(fmt, ...) printf("DEBUG: %s:%d: " fmt "\n", __FILE__, __LINE__, __VA_ARGS__)
// PRINT_DEBUG("Funcion [%s]:", __func__);

#endif
