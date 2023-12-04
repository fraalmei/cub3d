/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:21:21 by fraalmei          #+#    #+#             */
/*   Updated: 2023/11/25 17:39:49 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// allocate space for a new string
	// and join two string in it
char	*ft_strjoin(char const *s1, char const *s2)
{
	void	*s;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	ft_strlcat(s, s1, ft_strlen(s1) + 1);
	ft_strlcat(s, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return ((char *) s);
}

	// same than before except free allocate memory of the first parameter
char	*ft_strjoin_onefree(char *s1, char const *s2)
{
	void	*s;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	ft_strlcat(s, s1, ft_strlen(s1) + 1);
	ft_strlcat(s, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (free(s1), (char *) s);
}

char	*ft_strjoin_allfree(char *s1, char *s2)
{
	void	*s;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	ft_strlcat(s, s1, ft_strlen(s1) + 1);
	ft_strlcat(s, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (free(s1), free(s2), (char *) s);
}

/// @brief join a string to a string array
/// @param s1 
/// @param s2 
/// @return 
char	**str_strjoin_onefree(char **s1, char const *s2)
{
	char	**str;
	int		str_len;
	int		i;

	if (!s1)
		s1 = (char **)ft_calloc(sizeof(char *), 1);
	if (!s1)
		return (NULL);
	str_len = ft_str_strlen(s1);
	i = -1;
	str = (char **)ft_calloc(sizeof(char *), str_len + 2);
	while (s1[++i])
		str[i] = s1[i];
	free (s1);
	str[i] = ft_strdup(s2);
	return (str);
}

/// @brief join a string to a string array
/// @param s1 
/// @param s2 
/// @return 
char	**str_strjoin_freeall(char **s1, char *s2)
{
	char	**str;
	int		str_len;
	int		i;

	if (!s1)
		s1 = (char **)ft_calloc(sizeof(char *), 1);
	if (!s1)
		return (NULL);
	str_len = ft_str_strlen(s1);
	i = -1;
	str = (char **)ft_calloc(sizeof(char *), str_len + 2);
	while (s1[++i])
		str[i] = s1[i];
	free (s1);
	str[i] = s2;
	return (str);
}
