/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:00:58 by marvin            #+#    #+#             */
/*   Updated: 2021/02/05 17:00:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_double(t_flag *flag, va_list argptr)
{
	double	nbr;
	long	postpoint;
	long	prepoint;
	char	*pre;
	char	*post;
	//int		size;
	//int		pad_true;
	//char 	*freeme;

	nbr = va_arg(argptr, double);
	prepoint = (long)nbr;
	nbr = nbr - (double)prepoint;
	postpoint = nbr * 1000000;
	pre = ft_itoa_base(prepoint, "0123456789");
	post = ft_itoa_base(postpoint, "0123456789");
	//freeme = nbr;
	/*size = ft_strlen(pre) + ft_strlen(post);
	if (*nbr == '-' && flag->prec >= size)
		flag->pad--;
	if (flag->pad >= size && flag->pad > flag->prec )
	{
		if (flag->pad > flag->prec && flag->prec != -1)
			flag->whidt_c = ' ';
		if (size <= flag->prec)
			flag->pad -= flag->prec;
		if (size > flag->prec && !(*nbr == '0' && flag->prec == 0))
			flag->pad -= size;
		pad_true = 1;
	}
	if (pad_true && !flag->left && flag->prec != -1)
		ft_padding(flag);
	if (*nbr == '-')
		{
			ft_write_count("-", 1, flag);
			size--;
			nbr++;
		}
	if (pad_true && !flag->left && flag->prec == -1)
		ft_padding(flag);
	if (size < flag->prec)
	{
		while (size != flag->prec)
		{
			ft_write_count("0", 1, flag);
			flag->prec--;
		}
	}*/
	if (flag->prec /*|| *nbr != '0'*/)
	{
		ft_write_count(pre, ft_strlen(pre), flag);
		ft_write_count(".", 1, flag);
		ft_write_count(post, ft_strlen(post), flag);
	}
	free(pre);
	free(post);
	//free(freeme);
	/*if (pad_true && flag->left)
		ft_padding(flag);*/
}
