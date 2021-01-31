/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:50:02 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 15:33:22 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_integer(t_flag *flag, va_list argptr)
{
	char	*nbr;
	int		size;
	int		pad_true;

	pad_true = 0;
	nbr = ft_itoa_base((long)va_arg(argptr, int), "0123456789");
	size = ft_strlen(nbr);
	if (*nbr == '-' && flag->prec)
		flag->pad--;
	if (flag->pad > size && flag->pad > flag->prec)
	{
		if (flag->pad > flag->prec && flag->prec)
			flag->whidt_c = ' ';
		if (size <= flag->prec)
			flag->pad -= flag->prec;
		if (size > flag->prec)
			flag->pad -= size;
		pad_true = 1;
	}
	if (pad_true && !flag->left && flag->prec)
		ft_padding(flag);
	if (*nbr == '-')
		{
			ft_write_count("-", 1, flag);
			size--;
			nbr++;
		}
	if (pad_true && !flag->left && !flag->prec)
		ft_padding(flag);
	if (size < flag->prec)
	{

		while (size != flag->prec)
		{
			ft_write_count("0", 1, flag);
			flag->prec--;
		}
	}
	ft_write_count(nbr, size, flag);
	if (pad_true && flag->left)
		ft_padding(flag);
}
