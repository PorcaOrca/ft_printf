/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:57:40 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/04 19:05:00 by marvin           ###   ########.fr       */
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
