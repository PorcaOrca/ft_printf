/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:01:45 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/30 11:32:19 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	if (argc != 3)
	printf("Sucker printf = |%.5s|\n", "pizza pie");
	ft_printf("My lol printf = |%.5s|\n", "pizza pie");
	return (0);
}
