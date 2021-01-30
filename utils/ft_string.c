/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:57:44 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/30 17:25:21 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_padding(t_flag *flag)
{
	char	w_c;

	while (flag->pad)
	{
		write(1, &flag->whidt_c, 1);
		flag->pad--;
	}
}

void	ft_string(t_flag *flag, va_list argptr)
{
	char	*argstr;
	char	*prec_size;
	int		strl;

	argstr = va_arg(argptr, char *);
	strl = ft_strlen(argstr);
	if (flag->prec < strl && flag->prec)
	{
		prec_size = &argstr[flag->prec - 1];
		*prec_size = '\0';
	}
	flag->pad -= strl;
	if (!flag->left && flag->pad > 0)
		ft_padding(flag);
	ft_putstr_fd(argstr, 1);
	if (flag->left && flag->left > 0)
		ft_padding(flag);
}
