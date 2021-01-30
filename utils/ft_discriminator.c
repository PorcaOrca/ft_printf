/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discriminator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:06:22 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/30 17:23:38 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_discriminator(char *str, t_flag *flag, va_list argptr)
{
	//if (*str == 'd' || *str == 'i' || *str == 'u')
	//	ft_integer();
	//else if (*str == 'x' || *str == 'X')
	//	ft_hexa();
	//if (*str == 'c')
	//	ft_character();
	if (*str == 's')
		ft_string(flag, argptr);
	//else if (*str == 'p')
	//	ft_ptr_address();
}
