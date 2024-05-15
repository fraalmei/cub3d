/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:55:54 by cagonzal          #+#    #+#             */
/*   Updated: 2024/05/15 16:23:14 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len);
	ft_strlcat(ret, s2, len);
	ret[len] = '\0';
	return (ret);
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

	// same than before except free allocate memory of all arguments
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