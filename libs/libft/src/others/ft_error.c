/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:04:38 by vpujalte          #+#    #+#             */
/*   Updated: 2024/03/18 10:15:16 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_error(int error)
{
	if (error >= 0)
	{
		ft_putstr_fd("Error - ", STDERR);
		ft_putstr_fd(strerror(errno), STDERR);
		ft_putstr_fd("\n", STDERR);
		exit(errno);
	}
	else
	{
		if (error == -1)
			ft_putstr_fd("Error - Invalid number of arguments\n", STDERR);
		if (error == -2)
			ft_putstr_fd("Error - Duplicated values.\n", STDERR);
		if (error == -3)
			ft_putstr_fd("Error - No int found in args\n", STDERR);
		if (error == -4)
			ft_putstr_fd("Error - Int Overflow\n", STDERR);
		if (error == -5)
			ft_putstr_fd("Error - Not valid input in arg.\n", STDERR);
		if (error == -6)
			ft_putstr_fd("Error - Unknown error\n", STDERR);
		exit(0);
	}
}
