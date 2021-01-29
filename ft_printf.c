/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 08:42:31 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/29 16:11:32 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char *str, ...)
{
	va_list		argptr;
	int			left;
	char		c_just;
	int			pad;
	int			prec;

	pad = 0;
	prec = 0;
	c_just = ' ';
	left = 0;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = ft_flags(str, &left, &c_just);
			str = ft_widht(str, &pad, argptr);
			str = ft_precision(str, &prec, argptr);
			ft_discriminator(str);
		}
		else
			write(1, str, 1);
	if (*str)
		str++;
	}
	va_end(argptr);
	return (1);
}

int		main(void)
{
	ft_printf("My lol printf = |%08d|\n\t\t|%*.*d|\n", -256, 6, 9, 2534);
	printf("Sucker printf = |%08d|\n\t\t|%*.*d|\n", -256, 6, 9, 2534);
	return (0);
}
