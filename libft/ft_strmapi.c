/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:00:14 by fraalmei          #+#    #+#             */
/*   Updated: 2023/11/25 15:57:01 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// apply the function f to every character of "s"
	// to create a new string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	c = ft_strdup(s);
	if (!c)
		return (NULL);
	while (c[i])
	{
		c[i] = (*f)(i, c[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}

/* int	ft_strstrmap_i(char const **s, int (*f)(unsigned int, char*))
{
	unsigned int	i;
	int				e;

	i = 0;
	e = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[i])
	{
		e += (*f)(i, s[i]);
	}
	return (i);
} */
