/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:50:02 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 12:01:53 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_spaghetti(t_flag *flag, int size, char *nbr)
{
	int		pad_true;

	pad_true = 0;
	if (*nbr == '-' && flag->prec >= size)
		flag->pad--;
	if (flag->pad >= size && flag->pad > flag->prec)
	{
		if (flag->pad > flag->prec && flag->prec != -1)
			flag->whidt_c = ' ';
		if (size <= flag->prec)
			flag->pad -= flag->prec;
		if (size > flag->prec && !(*nbr == '0' && flag->prec == 0))
			flag->pad -= size;
		pad_true = 1;
	}
	return (pad_true);
}

static char	*ft_prearg(t_flag *flag, int pad_true, int *size, char *nbr)
{
	if (pad_true && !flag->left && (flag->prec > -1 || flag->whidt_c == ' '))
		ft_padding(flag);
	if (*nbr == '-')
	{
		ft_write_count("-", 1, flag);
		*size -= 1;
		nbr++;
	}
	if (pad_true && !flag->left && (flag->prec == -1 || flag->whidt_c == '0'))
		ft_padding(flag);
	if (*size < flag->prec)
	{
		while (*size != flag->prec)
		{
			ft_write_count("0", 1, flag);
			flag->prec--;
		}
	}
	return (nbr);
}

void		ft_integer(t_flag *flag, va_list argptr, char *base)
{
	char	*nbr;
	int		size;
	int		pad_true;
	char	*freeme;

	if (!(nbr = ft_itoa_base((long)va_arg(argptr, int), base)))
		return ;
	freeme = nbr;
	size = ft_strlen(nbr);
	pad_true = ft_spaghetti(flag, size, nbr);
	nbr = ft_prearg(flag, pad_true, &size, nbr);
	if (flag->prec || *nbr != '0')
		ft_write_count(nbr, size, flag);
	free(freeme);
	if (pad_true && flag->left)
		ft_padding(flag);
}
