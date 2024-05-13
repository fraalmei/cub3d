/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:09:09 by cagonzal          #+#    #+#             */
/*   Updated: 2024/03/18 10:20:10 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#ifndef uintptr_t
# define uintptr_t unsigned long long int
#endif

#ifndef UNS_INT
# define UNS_INT unsigned int
#endif

static int	ft_putstr(char *s, int fd)
{
	int		len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)", fd));
	while (*s)
		len += write(fd, &*s++, 1);
	return (len);
}

static int	ft_putnbr(long long int nbr, long long int i, char *base, int fd)
{
	int		len;

	len = 0;
	if (nbr < 0)
	{
		len += write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= i)
		len += ft_putnbr(nbr / i, i, base, fd);
	len += write(fd, &base[nbr % i], 1);
	return (len);
}

	// it's a modified putnbr to print the start of a "pointer"
static int	ft_putptr(uintptr_t nbr, unsigned int i, char *base, int fd)
{
	int		len;

	len = 0;
	if (nbr >= i)
		len += ft_putnbr(nbr / i, i, base, fd);
	len += write(fd, &base[nbr % i], 1);
	return (len);
}

	// the function to check de variable and act consequently
static int	ft_selector(char str, va_list args, int fd)
{
	int		len;
	char	c;

	len = 0;
	if (str == 'c')
	{
		c = va_arg(args, int);
		len += write(fd, &c, 1);
	}
	else if (str == 's')
		len += ft_putstr(va_arg(args, char *), fd);
	else if (str == 'p')
		len += ft_putstr("0x", fd)
			+ ft_putptr(va_arg(args, uintptr_t), 16, "0123456789abcdef", fd);
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(args, int), 10, "0123456789", fd);
	else if (str == 'u')
		len += ft_putnbr(va_arg(args, UNS_INT), 10, "0123456789", fd);
	else if (str == 'x')
		len += ft_putnbr(va_arg(args, UNS_INT), 16, "0123456789abcdef", fd);
	else if (str == 'X')
		len += ft_putnbr(va_arg(args, UNS_INT), 16, "0123456789ABCDEF", fd);
	else if (str == '%')
		len += write(fd, "%", 1);
	return (len);
}

	// to start printf create a len to count the printed chars
	// and start the list of variadic arguments
int	ft_printf_fd(int fd, char const *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str != '%')
			len += write(fd, str++, 1);
		else
		{
			str++;
			if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
				|| *str == 'i' || *str == 'u' || *str == 'x'
				|| *str == 'X' || *str == '%')
				len += ft_selector(*str, args, fd);
			else if (*str != '\0')
				len += write(fd, str, 1);
			else
				break ;
			str++;
		}
	}
	va_end(args);
	return (len);
}
