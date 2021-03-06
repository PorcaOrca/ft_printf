/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:32:00 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 11:34:29 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_precision(char *str, int *prec, va_list argptr)
{
	if (*str == '.')
	{
		str++;
		*prec = 0;
		if (*str == '*')
		{
			*prec = va_arg(argptr, int);
			str++;
			return (str);
		}
		else
		{
			while (ft_isdigit(*str))
			{
				*prec *= 10;
				*prec += (*str - '0');
				str++;
			}
			return (str);
		}
	}
	return (str);
}
