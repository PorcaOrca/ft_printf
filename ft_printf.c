/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 08:42:31 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/30 12:23:54 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char *str, ...)
{
	va_list		argptr;
	int			flag[4];

	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = ft_flags(str, &flag[0], &flag[1]);
			str = ft_widht(str, &flag[2], argptr);
			write(1, "err1\n", 5);
			str = ft_precision(str, &flag[3], argptr);
			write(1, "err2\n", 5);
			ft_discriminator(str, flag, argptr);
		}
		else
			write(1, str, 1);
		if (*str)
			str++;
	}
	va_end(argptr);
	return (1);
}
