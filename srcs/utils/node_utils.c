/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:26:10 by fraalmei          #+#    #+#             */
/*   Updated: 2024/06/29 13:00:11 by fraalmei         ###   ########.fr       */
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

int	ft_chrcmp_str(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_del_str_arr_chr_cmp(char c, char ***arr)
{
	int	i;

	if (*arr[0])
		return (0);
	i = -1;
	while (*arr[++i])
	{
		if (ft_chrcmp_str(c, *arr[i] + 1) != -1)
		{
			if (*arr[i][0] == '0')
			{
				*arr[i][0] = '1';
				return (0);
			}
			else if (*arr[i][0] == '1')
				return (1);
		}
	}
	return (1);
}

int	ft_str_arr_cmp(char *str, char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (ft_strcmp(str, arr[i]) == 0)
			return (0);
	}
	return (1);
}

char	**del_node_arr(char **arr, char *str)
{
	int		i;
	char	**ret;

	if (!arr[0])
		return (arr);
	i = 0;
	ret = (char **)ft_calloc(sizeof(char *), 2);
	while (arr[i])
	{
		if (ft_strcmp(arr[i], str) != 0)
			ret = ft_arrayjoin_arrfree(ret, arr[i]);
		else
			free (arr[i]);
		i++;
	}
	free (arr);
	return (ret);
}
