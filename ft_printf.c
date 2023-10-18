/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:36:58 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 12:13:00 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_keyword(const char *string, va_list args, int *len, int index)
{
	if (string[index] == 'c')
		ft_putchar_len_fd(va_arg(args, int), len, 1);
	else if (string[index] == 's')
		ft_putstr_len_fd(va_arg(args, char *), len, 1);
	else if (string[index] == 'p')
		ft_putptr(va_arg(args, void *), len, 1);
	else if (string[index] == 'd' || string[index] == 'i')
		ft_putnbr_len_fd(va_arg(args, int), len, 1);
	else if (string[index] == 'u')
		ft_unsigned_putnbr_len_fd(va_arg(args, unsigned int), len, 1);
	else if (string[index] == 'x')
		ft_putnbr_hex_len_fd(va_arg(args, unsigned int), len, 1);
	else if (string[index] == 'X')
		ft_putnbr_hex_upper_len_fd(va_arg(args, unsigned int), len, 1);
	else if (string[index] == '%')
		ft_putchar_len_fd('%', len, 1);
}

int	ft_printf(const char *string, ...)
{
	va_list			args;
	int				i;
	int				len;

	len = 0;
	va_start(args, string);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			check_keyword(string, args, &len, i + 1);
			i++;
		}
		else
			ft_putchar_len_fd(string[i], &len, 1);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	ft_printf("%c", '0');
// }
