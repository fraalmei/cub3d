/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:18:41 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/18 10:14:58 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_isspace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (&str[i]);
}

static int	ft_cmp_p_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	if (i % 2 == 0)
		return (1);
	return (-1);
}

static char	*ft_position(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (&str[i]);
}

static void	is_int(long num)
{
	if (num < -2147483648 || num > 2147483647)
		ft_error(-1);
}

int	ft_atoi(const char *str)
{
	char		*ptr;
	int			i;
	int			j;
	int			nb;
	long		plus;

	i = 0;
	ptr = ft_position(ft_isspace((char *)str));
	if (ptr[0] < '0' || ptr[0] > '9')
		return (0);
	j = 0;
	while (ptr[j] >= '0' && ptr[j] <= '9')
		j++;
	plus = 0;
	while (i < j)
	{
		nb = ptr[i] - '0';
		plus += nb;
		if (i < j - 1)
			plus *= 10;
		i++;
	}
	plus *= ft_cmp_p_n(ft_isspace((char *)str));
	is_int(plus);
	return (plus);
}
