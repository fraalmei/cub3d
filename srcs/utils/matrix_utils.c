/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:20:23 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/29 17:48:36 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/// @brief fill the right of the matrix to set the matrix a square
/// @param map 
/// @return a 0 if it works
int	fill_matrix(char ***matrix, char c)
{
	int		max_row;
	int		i;
	int		swap_max;

	i = 0;
	max_row = 0;
	while (matrix[0][i])
	{
		swap_max = 0;
		while (matrix[0][i][swap_max])
			swap_max++;
		if (swap_max > max_row)
			max_row = swap_max;
		i++;
	}
	i = -1;
	while (matrix[0][++i])
	{
		swap_max = -1;
		while (++swap_max < max_row)
			if (!matrix[0][i][swap_max])
				matrix[0][i] = ft_chrjoin(matrix[0][i], c);
	}
	return (0);
}

t_size	matrix_len(char **matrix)
{
	t_size		len;

	len.height = ft_arraylen((const void **)matrix);
	len.width = ft_strlen(matrix[0]);
	return (len);
}