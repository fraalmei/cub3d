/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:35:13 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/27 15:34:19 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_arrayjoin_arrfree(char **array, const char *str)
{
	char	**new;
	size_t	len;
	size_t	i;

	if (!array && str)
		array = (char **)ft_calloc(sizeof(char *), 1);
	if (!array || !str)
		return (NULL);
	len = ft_arraylen ((const void **)array);
	new = (char **)ft_calloc(sizeof(char *), len + 2);
	if (!new)
		return (NULL);
	i = -1;
	while (len > ++i)
		new[i] = ft_strdup(array[i]);
	new[i] = ft_strdup(str);
	free (array);
	return (new);
}