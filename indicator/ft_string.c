/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:57:44 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 10:06:58 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_string(t_flag *flag, va_list argptr)
{
	char	*argstr;
	char	*prec_size;
	int		strl;

	argstr = va_arg(argptr, char *);
	strl = ft_strlen(argstr);
	if (flag->prec < strl)
		strl = flag->prec;
	flag->pad -= strl;
	if (!flag->left && flag->pad > 0)
		ft_padding(flag);
	write(1, argstr, strl);
	flag->count += strl;
	if (flag->left && flag->pad > 0)
		ft_padding(flag);
}
