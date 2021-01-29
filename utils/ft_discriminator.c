/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discriminator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:06:22 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/29 16:09:44 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_discriminator(char *str,)
{
	if (*str == 'd' || *str == 'i')
		ft_integer();
	else if (*str == 'u')
		ft_unsigned_int();
	else if (*str == 'x')
		ft_low_hexa();
	else if (*str == 'X')
		ft_up_hexa();
	else if (*str == 'c')
		ft_character();
	else if (*str == 's')
		ft_string();
	else if (*str == 'p')
		ft_ptr_address();
}
