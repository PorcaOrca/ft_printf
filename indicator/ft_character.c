/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:57:07 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 11:40:04 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_character(t_flag *flag, va_list argptr)
{
	char	argchar;

	argchar = (char)va_arg(argptr, unsigned int);
	if (flag->pad)
		flag->pad--;
	if (!flag->left)
		ft_padding(flag);
	ft_write_count(&argchar, 1, flag);
	if (flag->left)
		ft_padding(flag);
}
