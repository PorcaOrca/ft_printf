/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 07:54:40 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/04 07:54:40 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_ptr_address(t_flag *flag, va_list argptr, char* base)
{
	char	*nbr;
	int		size;
	int		pad_true;
	char 	*freeme;

	pad_true = 0;
	if (!(nbr = ft_itoa_base(va_arg(argptr, unsigned long), base)))
		return ;
	freeme = nbr;
	size = ft_strlen(nbr);
	if (*nbr == '-')
	{
			nbr++;
			size--;
	}
	//if (*nbr == '-' && flag->prec >= size)
	//	flag->pad--;
	if (flag->pad >= size && flag->pad > flag->prec )
	{
		if (flag->pad > flag->prec && flag->prec != -1)
			flag->whidt_c = ' ';
		if (size <= flag->prec)
			flag->pad -= flag->prec;
		if (size > flag->prec && !(*nbr == '0' && flag->prec == 0))
			flag->pad -= (size + 2);
		pad_true = 1;
	}
	//if (pad_true && !flag->left && flag->prec != -1)
	//	ft_padding(flag);
	//if (*nbr == '-')
	//	{
	//		ft_write_count("-", 1, flag);
	//		size--;
	//		nbr++;
	//	}
	if (pad_true && !flag->left && flag->prec == -1)
		ft_padding(flag);
	if (size < flag->prec)
	{
		while (size != flag->prec)
		{
			ft_write_count("0", 1, flag);
			flag->prec--;
		}
	}
	if (flag->prec || *nbr != '0')
	{
		ft_write_count("0x", 2, flag);	
		ft_write_count(nbr, size, flag);
	}
	free(freeme);
	if (pad_true && flag->left)
		ft_padding(flag);
}
