/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:38:39 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/18 13:15:31 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <t_list.h>

/**
 * @brief Destroys the given linked list.
 * 
 * @param lst Linked list.
 */
void	ft_lstclear(t_list **lst)
{
	if (lst == NULL || *lst == NULL)
		return ;
	ft_lstclear(&(*lst)->next);
	ft_lstdelone(*lst);
	*lst = NULL;
}
