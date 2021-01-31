/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 09:40:56 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 09:46:27 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_padding(t_flag *flag)
{
	while (flag->pad)
	{
		write(1, &flag->whidt_c, 1);
		flag->pad--;
		flag->count++;
	}
}
