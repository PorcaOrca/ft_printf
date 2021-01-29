/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:57:40 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/29 13:25:13 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_widht(char *str, int *pad, va_list argptr)
 {
	*pad = 0;
	if (*str == '*')
	{
		*pad = va_arg(argptr, int);
		str++;
		return (str);
	}
	else
	{
		while (ft_isdigit(*str))
		{
			*pad *= 10;
			*pad += (*str - '0');
			str++;
		}
		return (str);
	}
	return (str);
 }
