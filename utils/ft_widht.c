/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:57:40 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 11:34:02 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_widht(char *str, t_flag *flag, va_list argptr)
{
	if (*str == '*')
	{
		flag->pad = va_arg(argptr, int);
		if (flag->pad < 0)
		{
			flag->pad = -flag->pad;
			flag->left = 1;
			flag->whidt_c = ' ';
		}
		str++;
		return (str);
	}
	else
	{
		while (ft_isdigit(*str))
		{
			flag->pad *= 10;
			flag->pad += (*str - '0');
			str++;
		}
		return (str);
	}
	return (str);
}
