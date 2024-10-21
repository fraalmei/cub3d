/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:54:52 by fraalmei          #+#    #+#             */
/*   Updated: 2024/10/11 12:11:08 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/// @brief print an array of strings
/// @param str 
/// @return the string printed
int	print_arr(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		ft_printf_fd (1, "%s\n", str[i]);
		i++;
	}
	return (i);
}

int	print_arr_uint8_t(uint8_t *i)
{
	int	l;

	if (!i)
		return (1);
	l = 0;
	while (i[l])
	{
		printf("%d ", i[l]);
		l++;
	}
	printf("\n");
	return (0);
}
