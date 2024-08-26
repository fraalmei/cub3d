/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:34:09 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/18 10:21:42 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	if (c == '\0')
		return ((char *)tmp);
	while (--tmp >= str)
		if (*tmp == (unsigned char)c)
			return ((char *)tmp);
	return (0);
}
