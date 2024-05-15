/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:26:10 by fraalmei          #+#    #+#             */
/*   Updated: 2024/05/15 11:28:58 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// its for strings with no duplicates
// it deletes the char of the strings
// if the char its founded 
/* char	*del_char_str(char *str, char c)
{
	int		i;
	int		char_finded;
	char	*ret;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	char_finded = 0;
	while (i > 0)
	{
		if (str[i] != c)
			ret = ft_chrjoin(ret, str[i]);
		else if (char_finded > 0)
			return (free (ret), NULL);
		else
			char_finded++;
		i--;
	}
	free (str);
	return (ret);
} */

/* char	**str_array(char line)
{
	char	**arr;
	int		i;

	i = 0;
	while (line)
		arr = ft_strjoin_onefree(arr, get_next_word(line, i++));
	return (arr);
} */

/* char	**del_node_arr(char **arr, char *str)
{
	int		i;
	char	**ret;

	if (!arr)
		return (NULL);
	i = 0;
	ret = NULL;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], str) != 0)
			ret = str_strjoin_onefree(ret, arr[i]);
		i++;
	}
	free (arr);
	return (ret);
} */

int	print_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printf_fd (1, "%s\n", str[i]);
		i++;
	}
	return (i);
}

static void	ignore_no_p(char *buffer, int *i)
{
	while (buffer[*i] <= ' ')
		*i += 1;
}

/// @brief Read and extract a word from the command buffer.
/// This function reads a word from the command buffer
/// starting at the specified position (i) and
/// returns the extracted word as a dynamically allocated string.
/// A word is defined as a sequence of characters
/// that are not spaces or redirection symbols.
/// @param buffer The original command buffer containing words and symbols.
/// @param i A pointer to the iterator position in the original command buffer .
/// @return A dynamically allocated string containing the extracted word.
/// @note The function expects `buffer`
/// to contain the command with words and symbols.
/// @note It updates `i` to the next position after the extracted word.
/// @note The function handles both single and double quotes
/// as well as redirection symbols.
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
	while(str[i] && w >= i)
	{
		if (i == w)
			word = read_word(str, &l);
		else
			word = (free(read_word(str, &l)), NULL);
		i++;
	}
	return (word);
}
