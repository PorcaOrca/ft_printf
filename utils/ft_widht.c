/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:57:40 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/28 14:55:47 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft.h"

char		*ft_widht(char *str, int *pad, va_list argptr)
 {
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
