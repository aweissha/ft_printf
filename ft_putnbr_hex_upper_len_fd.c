/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upper_len_fd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:08:27 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 11:24:48 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_upper_len_fd(unsigned int nbr, int *len, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_len_fd('-', len, fd);
		nbr = nbr * (-1);
	}
	if (nbr >= 16)
	{
		ft_putnbr_hex_upper_len_fd(nbr / 16, len, fd);
		ft_putchar_len_fd("0123456789ABCDEF"[nbr % 16], len, fd);
	}
	else
		ft_putchar_len_fd("0123456789ABCDEF"[nbr % 16], len, fd);
}
