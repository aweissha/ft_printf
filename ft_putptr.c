/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:01:35 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 12:14:08 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr_hex_len_fd(unsigned long long nbr, int *len, int fd)
{
	if (nbr >= 16)
	{
		ft_putptr_hex_len_fd(nbr / 16, len, fd);
		ft_putchar_len_fd("0123456789abcdef"[nbr % 16], len, fd);
	}
	else
		ft_putchar_len_fd("0123456789abcdef"[nbr % 16], len, fd);
}

void	ft_putptr(void *p, int *len, int fd)
{
	unsigned long long	n;

	n = (unsigned long long)p;
	ft_putstr_len_fd("0x", len, fd);
	ft_putptr_hex_len_fd(n, len, fd);
}
