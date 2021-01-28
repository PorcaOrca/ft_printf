/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 08:42:31 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/28 15:24:43 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

int		ft_printf(char *str, ...)
{
	va_list		argptr;
	char		*temp;
	int			left;
	char		c_just;
	int			pad;
	int			n_lenght;
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
			if (*str == 'd')
			{
				temp = ft_itoa(va_arg(argptr, int));
				n_lenght = ft_strlen(temp);
				prec -= n_lenght;
				if (prec > 0)
					pad -= prec;
				pad -= n_lenght;
				if (!left && pad > 0)
				{
					while (pad--)
						ft_putchar_fd(c_just, 1);
				}
				if (*temp == '-')
				{
					ft_putchar_fd('-', 1);
					n_lenght--;
					temp++;
					prec++;
					pad--;
				}
				if (prec > 0)
				{
					while (prec--)
						ft_putchar_fd('0', 1);
				}
				while (n_lenght--)
				{
					ft_putchar_fd(*temp, 1);
					temp++;
				}
				if (left && pad > 0)
				{
					while (pad--)
						ft_putchar_fd(c_just, 1);
				}
			}
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
	ft_printf("My lol printf = |%-9.6d|\n", 256);
	printf("Sucker printf = |%-9.6d|\n", 256);
	return (0);
}
