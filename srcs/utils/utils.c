/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:26:10 by fraalmei          #+#    #+#             */
/*   Updated: 2023/12/11 16:58:13 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**str_array(char line)
{
	char	**arr;
	int		i;

	i = 0;
	while (line)
		arr = ft_strjoin_onefree(arr, get_next_word(line, i++));
	return (arr);
}

void	del_node_arr(char **arr, char str)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], str) == 0)
		{
			free (arr[i]);
			while (arr[i + 1])
			{
				arr[i] = arr[i + 1];
				i++;
			}
			arr[i] = NULL;
		}
		i++;
	}
}
