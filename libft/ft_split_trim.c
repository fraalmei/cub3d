/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:42:05 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/16 19:15:37 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// count how many pointers have "string"
int	ft_str_strlen(char **string)
{
	int	i;

	i = 0;
	while (string && string[i])
		i++;
	return (i);
}

	// count the number of characcters until thesecond char is finded
int	ft_scndchrlen(const char *s, char c)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (n < 2 && s[++i])
	{
		if (s[i] == c)
			n++;
	}
	if (s[i])
		return (i);
	else
		return (-1);
}

char	*ft_last_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (str[i - 1]);
}
