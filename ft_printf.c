/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:36:58 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/16 19:19:20 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"


void ft_putptr_hex_fd(void *p, int fd)
{
	size_t	n;

	n = (size_t)p;
	if (n >= 16)
	{
		ft_putnbr_fd(n / 16, fd);
		ft_putchar_fd("0123456789abcdef"[n % 16], fd);
	}
	else
		ft_putchar_fd("0123456789abcdef"[n % 16], fd);
}

void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd((n % 10) + '0', fd);
}


void ft_putnbr_hex_fd(int nbr, int fd)
{
	long	n;
	
	n = (long)nbr;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if (n >= 16)
	{
		ft_putnbr_fd(n / 16, fd);
		ft_putchar_fd("0123456789abcdef"[n % 16], fd);
	}
	else
		ft_putchar_fd("0123456789abcdef"[n % 16], fd);
}

void ft_putnbr_hex_upper_fd(int nbr, int fd)
{
	long	n;
	
	n = (long)nbr;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if (n >= 16)
	{
		ft_putnbr_fd(n / 16, fd);
		ft_putchar_fd("0123456789ABCDEF"[n % 16], fd);
	}
	else
		ft_putchar_fd("0123456789ABCDEF"[n % 16], fd);
}

int	check_keyword(const char *string, va_list args, int index)
{
	if (string[index] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);		
	else if (string[index] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (string[index] == 'p')
		ft_putptr_hex_fd(va_arg(args, void *), 1);
	else if (string[index] == 'd' || string[index] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (string[index] == 'u')
		ft_unsigned_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (string[index] == 'x')
		ft_putnbr_hex_fd(va_arg(args, int), 1);
	else if (string[index] == 'X')
		ft_putnbr_hex_upper_fd(va_arg(args, int), 1);
	else if (string[index] == '%')
		ft_putchar_fd('%', 1);
	else
		return (0);
	return (1);
}



int	ft_printf(const char *string, ...)
{
	va_list	args;
	int	i;
	
	va_start(args, string);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%' && check_keyword(string, args, i + 1) != 0)
			i++;
		else
			ft_putchar_fd(string[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}
int main(void)
{
	ft_printf("bl%sabla%ib%%la%c", "Ich heisse Alex", 123, 'a');
}
