/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:57:07 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 10:29:45 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_percent(t_flag *flag)
{
	char	percent;

	percent = '%';
	if (flag->pad)
		flag->pad--;
	if (!flag->left)
		ft_padding(flag);
	ft_write_count(&percent, 1, flag);
	if (flag->left)
		ft_padding(flag);
}
