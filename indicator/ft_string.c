/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:57:44 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/05 11:05:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_string(t_flag *flag, va_list argptr)
{
	char	*argstr;
	int		strl;

	argstr = va_arg(argptr, char *);
	if (!argstr)
	{
		ft_write_count("(null)", 6, flag);
		return ;
	}
	if (*argstr == '\0')
		return ;
	strl = ft_strlen(argstr);
	if (flag->prec < strl && flag->prec != -1)
		strl = flag->prec;
	flag->pad -= strl;
	if (!flag->left && flag->pad > 0)
		ft_padding(flag);
	ft_write_count(argstr, strl, flag);
	if (flag->left && flag->pad > 0)
		ft_padding(flag);
}
