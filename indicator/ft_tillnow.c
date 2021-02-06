/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tillnow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:06:34 by marvin            #+#    #+#             */
/*   Updated: 2021/02/05 16:06:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_tillnow(t_flag *flag, va_list argptr)
{
	int		*printed;

	printed = (int *)va_arg(argptr, void *);
	*printed = flag->count;
}