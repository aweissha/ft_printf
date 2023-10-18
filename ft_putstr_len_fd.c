/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:04:19 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 12:30:05 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len_fd(char *s, int *len, int fd)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		(*len) += 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			(*len)++;
			i++;
		}
	}
}
// int main(void)
// {
// 	char s[] = "blablabla";
// 	ft_putstr_fd(s, 1);
// }
