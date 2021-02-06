/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:00:55 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/05 18:11:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int *ptr;
	ptr = (int *)malloc(sizeof(int) * 1);
	printf("pointer = |%5.8%|\n");
	//printf("value of n = |%d|", *ptr);
	return(0);
}
