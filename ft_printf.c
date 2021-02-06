/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 08:42:31 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/05 10:47:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *input, ...)
{
	va_list		argptr;
	t_flag		flag;
	char		*str;

	str = (char *)input;
	va_start(argptr, input);
	flag.count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_start_up(&flag);
			str = ft_flags(str, &flag.left, &flag.whidt_c);
			str = ft_widht(str, &flag, argptr);
			str = ft_precision(str, &flag.prec, argptr);
			ft_discriminator(str, &flag, argptr);
			if (*str == '%')
				ft_write_count("%", 1, &flag);
		}
		else
			ft_write_count(str, 1, &flag);
		if (*str)
			str++;
	}
	va_end(argptr);
	return (flag.count);
}
