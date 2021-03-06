/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discriminator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:06:22 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 11:55:56 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_discriminator(char *str, t_flag *flag, va_list argptr)
{
	if (*str == 'd' || *str == 'i')
		ft_integer(flag, argptr, "0123456789");
	else if (*str == 'u')
		ft_hexa(flag, argptr, "0123456789");
	else if (*str == 'x')
		ft_hexa(flag, argptr, "0123456789abcdef");
	else if (*str == 'X')
		ft_hexa(flag, argptr, "0123456789ABCDEF");
	else if (*str == 'c')
		ft_character(flag, argptr);
	else if (*str == 's')
		ft_string(flag, argptr);
	else if (*str == 'p')
		ft_ptr_address(flag, argptr, "0123456789abcdef");
	else if (*str == '%')
		ft_percent(flag);
}
