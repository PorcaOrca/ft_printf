/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:31:11 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 12:31:34 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_spaghetti(t_flag *flag, int size, char *nbr)
{
	int		pad_true;

	pad_true = 0;
	if (flag->pad >= (size + 2) && flag->pad > flag->prec)
	{
		if (flag->pad > flag->prec && flag->prec != -1)
			flag->whidt_c = ' ';
		if (size <= flag->prec)
			flag->pad -= flag->prec;
		if (size > flag->prec && !(*nbr == '0' && flag->prec == 0))
			flag->pad -= (size + 2);
		else
			flag->pad -= 2;
		pad_true = 1;
	}
	return (pad_true);
}

void		ft_ptr_address(t_flag *flag, va_list argptr, char *base)
{
	char	*nbr;
	int		size;
	int		pad_true;
	char	*freeme;

	if (!(nbr = ft_itoa_base_ptr(va_arg(argptr, unsigned long long), base)))
		return ;
	freeme = nbr;
	size = ft_strlen(nbr);
	pad_true = ft_spaghetti(flag, size, nbr);
	if (pad_true && !flag->left && (flag->prec == -1 || flag->whidt_c == ' '))
		ft_padding(flag);
	ft_write_count("0x", 2, flag);
	if (size < flag->prec)
		while (size != flag->prec)
		{
			ft_write_count("0", 1, flag);
			flag->prec--;
		}
	if (flag->prec || *nbr != '0')
		ft_write_count(nbr, size, flag);
	free(freeme);
	if (pad_true && flag->left)
		ft_padding(flag);
}
