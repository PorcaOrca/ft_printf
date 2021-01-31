/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:57:07 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 11:34:00 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_character(t_flag *flag, va_list argptr)
{
	char	argchar;

	argchar = va_arg(argptr, int);
	flag->pad--;
	if (!flag->left)
		ft_padding(flag);
	write(1, &argchar, 1);
	flag->count++;
	if (flag->left)
		ft_padding(flag);
}
