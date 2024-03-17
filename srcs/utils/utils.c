/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:26:10 by fraalmei          #+#    #+#             */
/*   Updated: 2024/03/17 14:34:19 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// its for strings with no duplicates
// it deletes the char of the strings
// if the char its founded 
char	*del_char_str(char *str, char c)
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
}

/* char	**str_array(char line)
{
	char	**arr;
	int		i;

	i = 0;
	while (line)
		arr = ft_strjoin_onefree(arr, get_next_word(line, i++));
	return (arr);
} */

char	**del_node_arr(char **arr, char *str)
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
}
