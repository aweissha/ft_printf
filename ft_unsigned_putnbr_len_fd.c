/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_len_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:04:32 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 16:17:50 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_putnbr_len_fd(unsigned int n, int *len, int fd)
{
	if (n >= 10)
	{
		ft_unsigned_putnbr_len_fd(n / 10, len, fd);
		if ((*len) != -1)
			ft_putchar_len_fd((n % 10) + '0', len, fd);
	}
	else
		if ((*len) != -1)
			ft_putchar_len_fd((n % 10) + '0', len, fd);
}
