/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:57:44 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/30 12:38:38 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_padding(int *flag)
{
	char	w_c;

	w_c = ' ';
	if (flag[1])
		w_c = '0';
	while (flag[2])
	{
		write(1, &w_c, 1);
		flag[2]--;
	}
}

void	ft_string(int *flag, va_list argptr)
{
	char	*argstr;
	char	*prec;
	int		strl;

	argstr = va_arg(argptr, char *);
	strl = ft_strlen(argstr);
	if (flag[3] < strl && flag[3])
	{
		prec = &argstr[flag[3] - 1];
		*prec = '\0';
	}
	flag[2] -= strl;
	write(1, "err4\n", 5);
	if (!flag[0] && flag[2] > 0)
		ft_padding(flag);
	ft_putstr_fd(argstr, 1);
	if (flag[0] && flag[2] > 0)
		ft_padding(flag);
}
