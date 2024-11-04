/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:51:39 by fraalmei          #+#    #+#             */
/*   Updated: 2024/11/02 01:51:34 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

	// alternative version of strjoin to join a char 
	// to a string and return a new string freeing the old string
char	*ft_chrjoin(char *s1, char s2)
{
	char	*s;
	int		i;

	i = 0;
	if (!s2 && s1)
		return (s1);
	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	s = (char *)ft_calloc(sizeof(char), i + 2);
	if (!s)
		return (s1);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	s[i++] = s2;
	s[i] = '\0';
	free(s1);
	return (s);
}

char	*ft_chr_n_join(char *s1, char *s2, int n)
{
	char	*s;
	int		i;
	int		m;

	i = 0;
	if (!s1)
		s1 = (char *)ft_calloc(sizeof(char), 1);
	while (s1[i])
		i++;
	s = ft_calloc(sizeof(char), i + n + 1);
	if (!s || s1 == NULL || s2 == 0)
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	m = 0;
	while (n > m)
		s[i++] = s2[m++];
	s[i] = '\0';
	free(s1);
	return ((char *) s);
}
