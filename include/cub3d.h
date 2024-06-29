/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:06:24 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/30 00:44:07 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <mlx.h>

# include "key_linux.h"
# include "keys.h"
# include "engine.h"
# include "structs.h"
# include "functions.h"
# include "../vector/src/vector.h"
# include "../libft/include/libft.h"

#define PRINT_DEBUG(fmt, ...) printf("DEBUG: %s:%d: " fmt "\n", __FILE__, __LINE__, __VA_ARGS__)
// PRINT_DEBUG("Funcion [%s]:", __func__);

#endif
