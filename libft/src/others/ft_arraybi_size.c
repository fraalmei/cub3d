/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraybi_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:40 by mortiz-d          #+#    #+#             */
/*   Updated: 2024/03/18 10:15:11 by cagonzal         ###   ########.fr       */
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
