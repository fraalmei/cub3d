/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:50:21 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/18 10:21:46 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len]))
		len--;
	ret = ft_substr(s1, 0, len + 1);
	return (ret);
}
