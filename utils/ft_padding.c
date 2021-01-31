/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 09:40:56 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 13:32:21 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_padding(t_flag *flag)
{
	while (flag->pad)
	{
		ft_write_count(&flag->whidt_c, 1, flag);
		flag->pad--;
	}
}
