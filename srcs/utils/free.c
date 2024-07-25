/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:56:02 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/25 13:43:03 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief free an array of voids
/// @param arr 
/// @return a 0 if end
int	free_arr(void **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free (arr[i]);
	free (arr);
	return (0);
}
