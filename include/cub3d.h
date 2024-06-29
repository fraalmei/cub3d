/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:06:24 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/28 13:50:14 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <mlx.h>

# if defined(__APPLE__)
#  include <key_macos.h>
# else
#  include <key_linux.h>
# endif

# include "structs.h"
# include <functions.h>
# include "../vector/src/vector.h"
# include "../libft/include/libft.h"
# include "../srcs/engine/include/engine.h"

#define PRINT_DEBUG(fmt, ...) printf("DEBUG: %s:%d: " fmt "\n", __FILE__, __LINE__, __VA_ARGS__)
// PRINT_DEBUG("Funcion [%s]:", __func__);

#endif
