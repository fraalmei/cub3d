/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:43:38 by p                 #+#    #+#             */
/*   Updated: 2024/11/04 13:45:40 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_str_fndd	**set_list_to_find(char *splitstring, char split)
{
	t_str_fndd	**list;
	char		**swap_split;
	int			len;
	int			i;

	swap_split = ft_split(splitstring, split);
	len = ft_str_arraylen(swap_split);
	list = (t_str_fndd **)ft_calloc(sizeof(t_str_fndd *), len + 1);
	i = -1;
	while (len > ++i)
	{
		list[i] = (t_str_fndd *)ft_calloc(sizeof(t_str_fndd), 1);
		list[i]->str = swap_split[i];
		list[i]->finded = FALSE;
	}
	free(swap_split);
	return (list);
}

/// @brief  check if the string side is in of the array sides
/// @param side 
/// @param sides 
/// @return a 0 if side is in sides, a 1 if not
int	check_list(char *str, t_str_fndd **list)
{
	int		i;

	i = -1;
	while (list[++i])
	{
		if (ft_strcmp(list[i]->str, str) == 0 && !list[i]->finded)
		{
			list[i]->finded = TRUE;
			return (0);
		}
	}
	return (1);
}

void	free_list(t_str_fndd **list)
{
	int		i;

	i = -1;
	while (list[++i])
	{
		free(list[i]->str);
		free(list[i]);
	}
	free(list);
}

int	str_fndd_list_len(t_str_fndd **list)
{
	int		i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

int	check_true_list(t_str_fndd **list)
{
	int		i;

	i = -1;
	while (list[++i])
		if (!list[i]->finded)
			return (1);
	return (0);
}
