/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:39:52 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/04 17:11:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_flags(char *str, int *left, char *whidt_c)
{
	if (*str == '-' || *str == '0')
	{
		if (*str == '-')
			*left = 1;
		else
			*whidt_c = '0';
		str++;
	}
	if (*str == '-' || *str == '0')
	{
		if (*str == '-')
		{
			*left = 1;
			*whidt_c = ' ';
		}
		else if (!*left)
			*whidt_c = '0';
		str++;
	}
	return (str);
}
