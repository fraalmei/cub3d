/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:37:47 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/18 10:22:41 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_list.h>

/**
 * @brief Deletes the given element with the given function.
 * 
 * @param lst Element to delete.
 */
void	ft_lstdelone(t_list *lst)
{
	if (lst == NULL)
		return ;
	free(lst);
}
