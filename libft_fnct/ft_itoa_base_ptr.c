/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:23:42 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 11:36:03 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		ft_converse_ptr(char *dest, char *base,
								unsigned long long nbr, long factor)
{
	int		mod;

	mod = nbr % factor;
	if (nbr < 0)
		mod = -mod;
	*dest = base[mod];
	nbr /= factor;
	if (nbr)
		ft_converse_ptr(--dest, base, nbr, factor);
}

char			*ft_itoa_base_ptr(unsigned long long nbr, char *base)
{
	unsigned long long	temp;
	long				size;
	char				*dest;
	long				factor;

	temp = nbr;
	size = 1;
	if (nbr < 0)
		size++;
	if (nbr == 0)
	{
		dest = ft_calloc(sizeof(char), 2);
		dest[0] = '0';
		return (dest);
	}
	factor = ft_strlen(base);
	while (temp /= factor)
		size++;
	if (!(dest = (char *)ft_calloc(sizeof(char), (size + 1))))
		return (NULL);
	ft_converse_ptr(&dest[size - 1], base, nbr, factor);
	if (nbr < 0)
		*dest = '-';
	return (dest);
}
