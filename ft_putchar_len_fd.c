/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_len_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:46:21 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 10:11:36 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len_fd(int c, int *len, int fd)
{
	write(fd, &c, 1);
	(*len)++;
}
// int main(void)
// {
// 	ft_putchar_fd('z', 1);
// }
