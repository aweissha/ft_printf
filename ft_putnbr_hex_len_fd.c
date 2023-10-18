/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_len_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:06:08 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 16:15:09 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_len_fd(unsigned int nbr, int *len, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_len_fd('-', len, fd);
		nbr = nbr * (-1);
	}
	if (nbr >= 16)
	{
		ft_putnbr_hex_len_fd(nbr / 16, len, fd);
		if ((*len) != -1)
			ft_putchar_len_fd("0123456789abcdef"[nbr % 16], len, fd);
	}
	else
		if ((*len) != -1)
			ft_putchar_len_fd("0123456789abcdef"[nbr % 16], len, fd);
}
