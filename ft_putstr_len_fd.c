/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:04:19 by aweissha          #+#    #+#             */
/*   Updated: 2023/10/18 16:21:06 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len_fd(char *s, int *len, int fd)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
	{
		if (write (fd, "(null)", 6) == -1)
			(*len) = -1;
		else
			(*len) += 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar_len_fd(s[i], len, fd);
			i++;
			if ((*len) == -1)
				break ;
		}
	}
}
// int main(void)
// {
// 	char s[] = "blablabla";
// 	ft_putstr_fd(s, 1);
// }
