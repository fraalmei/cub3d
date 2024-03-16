/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:06:18 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/16 12:36:23 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ignore_spaces(char *buffer, int *i)
{
	while (buffer[*i] && (buffer[*i] == ' ' || buffer[*i] == '\t'))
		*i += 1;
}

char	*get_next_word(char *line, int new)
{
	char			*word;
	char			c;
	static int		i;

	if (new == 0)
		i = 0;
	word = (char *)ft_calloc(sizeof(char), 2);
	ignore_spaces(line, &i);
	while (line[i] || ft_isprint(line[i]))
	{
		if (line[i] == 39 || line[i] == 34)
		{
			c = line[i];
			i++;
			while (line[i] && line[i] != c)
				word = ft_chrjoin(word, line[i++]);
		}
		else
			word = ft_chrjoin(word, line[i]);
		i++;
	}
	return (word);
}
