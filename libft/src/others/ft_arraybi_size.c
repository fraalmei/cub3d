/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraybi_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:40 by mortiz-d          #+#    #+#             */
/*   Updated: 2024/05/15 13:54:26 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_arraybi_size(char **str)
{
	int	tam;

	tam = 0;
	if (str != 0)
		while (str[tam] != 0)
			tam++;
	return (tam);
}

size_t	ft_arraylen(const void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
