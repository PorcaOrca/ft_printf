/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:01:45 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 16:43:29 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	int		my_ret;
	int		dumb_ret;
	char	*ez_gg;

	ez_gg = ft_calloc(sizeof(char), 2);
	if (argc != 3)
	dumb_ret = printf("Sucker printf = |%p|\n", ez_gg);
	my_ret = ft_printf("My lol printf = |%p|\n", ez_gg);
	printf("sucker return = |%d|\nmy lol return = |%d|", dumb_ret, my_ret);
	return (0);
}
