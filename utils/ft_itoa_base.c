/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:23:42 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/29 15:50:39 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_converse(char *dest, char *base, long nbr, long factor)
{
	int		mod;

	mod = nbr % factor;
	if (nbr < 0)
		mod = -mod;
	*dest = base[mod];
	if (nbr)
		ft_converse(--dest, base, nbr / factor, factor);
}

char		*ft_itoa_base(long nbr, char *base)
{
	long	temp;
	long	size;
	char	*dest;
	long	factor;

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
	ft_converse(&dest[size - 1], base, nbr, factor);
	if (nbr < 0)
		*dest = '-';
	return (dest);
}

int		main(void)
{
	char	*out;

	out = ft_itoa_base(-625384628367346, "0123456789ABCDEF");
	write(1, "hexadecimal = |", 15);
	write(1, out, ft_strlen(out));
	write(1, "|\n", 2);
	return(0);
}
