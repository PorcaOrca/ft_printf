/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 08:42:31 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 15:15:48 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *input, ...)
{
	va_list		argptr;
	t_flag		flag;
	char		*str;

	str = (char *)input;
	ft_start_up(&flag);
	va_start(argptr, input);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = ft_flags(str, &flag.left, &flag.whidt_c);
			str = ft_widht(str, &flag.pad, argptr);
			str = ft_precision(str, &flag.prec, argptr);
			ft_discriminator(str, &flag, argptr);
		}
		else
		{
			write(1, str, 1);
			flag.count++;
		}
		if (*str)
			str++;
	}
	va_end(argptr);
	return (flag.count);
}
