/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:01:45 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/05 15:00:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int		my_ret;
	int		dumb_ret;
	char	*ez_gg;

	//ez_gg = NULL;
	ez_gg = ft_calloc(sizeof(char), 2);
	dumb_ret = printf("Sucker printf = | %p |\n", 18446744073709551615);
	my_ret = ft_printf("My lol printf = | %p |\n", 18446744073709551615);
	printf("sucker return = |%d|\nmy lol return = |%d|\n", dumb_ret, my_ret);
	return (0);
}
