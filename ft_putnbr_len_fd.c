/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:20:37 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 16:52:06 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len_fd(int n, int *len, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_len_fd("-2", len, fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_len_fd('-', len, fd);
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_putnbr_len_fd(n / 10, len, fd);
		if ((*len) != -1)
			ft_putchar_len_fd((n % 10) + '0', len, fd);
	}
	else
		if ((*len) != -1)
			ft_putchar_len_fd((n % 10) + '0', len, fd);
}

// int main(void)
// {
// 	int n;

// 	n = 123;
// 	ft_putnbr_fd(n, 1);
// }
