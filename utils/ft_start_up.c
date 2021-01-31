/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:05:28 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 09:47:59 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_start_up(t_flag	*flag)
{
	flag->count = 0;
	flag->left = 0;
	flag->whidt_c = ' ';
	flag->pad = 0;
	flag->prec = 0;
}
