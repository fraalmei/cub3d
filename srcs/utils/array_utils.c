/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:26:10 by fraalmei          #+#    #+#             */
/*   Updated: 2024/07/25 14:21:16 by p                ###   ########.fr       */
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

/// @brief check if the character its into the string
/// @param c 
/// @param str 
/// @return a positive int if the char is finded, -1 if not
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

/// @brief delete a node of an array that contains the char
/// @param c 
/// @param arr 
/// @return a 1 no coincidences finded,0 if exist a coincidence
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

/// @brief compare a string to all nodes of an array
/// @param str 
/// @param arr 
/// @return 1 of no coincidences finded, 0 if exist a coincidence
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

/// @brief delete a node of an array
/// @param arr 
/// @param str 
/// @return return the array modified
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
