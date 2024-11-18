/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:35:14 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/18 13:07:17 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_list.h>

/**
 * @brief Returns the last element of a linked list.
 * 
 * @param lst Linked list.
 * @return t_list* Pointer to the last element.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL)
		return (ft_lstlast(lst->next));
	return (lst);
}
