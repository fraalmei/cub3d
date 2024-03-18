/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:34:10 by vminomiy          #+#    #+#             */
/*   Updated: 2024/03/18 10:14:47 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_abs(float num)
{
	int	tmp;

	tmp = (int)num;
	if ((num - tmp) >= 0.5)
		return ((int) num + 1);
	else
		return ((int) num);
}
