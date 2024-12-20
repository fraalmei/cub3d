/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:15:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/06/21 15:53:33 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	while (--n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

	// compare "needle" and the end of "haystack"
int	ft_str_last_cmp(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(haystack) - 1;
	j = ft_strlen(needle) - 1;
	if (i < j)
		return (1);
	while (haystack[i] && needle[j])
	{
		if (haystack[i] != needle[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}
