/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:50:57 by p                 #+#    #+#             */
/*   Updated: 2024/06/28 18:08:38 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ignore_no_p(char *buffer, int *i)
{
	while (buffer[*i] <= ' ')
		*i += 1;
}

/// @brief check if the line its empty (no character printed)
/// @param line 
/// @return 1 if it a empty line, 0 if its not empty
int	check_empty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]) == 0 || line[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}

char	*read_word(char *buffer, int *i)
{
	char	*word;
	char	c;

	if (buffer[*i] == '\n')
		return (NULL);
	ignore_no_p(buffer, i);
	word = (char *)ft_calloc(sizeof(char), 1);
	while (buffer[*i] && !(ft_isprint(buffer[*i]) == 0 || buffer[*i] == 32))
	{
		if (buffer[*i] == 39 || buffer[*i] == 34)
		{
			c = buffer[*i];
			i[0]++;
			while (buffer[*i] && buffer[*i] != c)
				word = ft_chrjoin(word, buffer[i[0]++]);
		}
		else
			word = ft_chrjoin(word, buffer[*i]);
		i[0]++;
	}
	return (word);
}

char	*get_word(char *str, int w)
{
	int		i;
	int		l;
	char	*word;

	i = 0;
	l = 0;
	word = NULL;
	while (str[i] && w >= i)
	{
		if (i == w)
			word = read_word(str, &l);
		else
			word = (free(read_word(str, &l)), NULL);
		i++;
	}
	return (word);
}

char	*get_next_notempty_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (ft_strcmp(line, "\n") == 0)
		line = (free (line), get_next_line(fd));
	return (line);
}
