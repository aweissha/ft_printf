/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hex_len_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:01:35 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/17 17:05:32 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_hex_len_fd(void *p, int *len, int fd)
{
	long	n;

	n = (long)p;
	ft_putstr_len_fd("0x", len, fd);
	ft_putnbr_hex_len_fd(n, len, fd);
}
