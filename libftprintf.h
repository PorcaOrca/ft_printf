/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:03:13 by lspazzin          #+#    #+#             */
/*   Updated: 2021/02/06 11:43:44 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int		count;
	int		left;
	char	whidt_c;
	int		pad;
	int		prec;
}				t_flag;

void			ft_bzero(void *s, size_t n);
int				ft_atoi(char *str);
size_t			ft_strlen(const char *str);
void			*ft_calloc(size_t count, size_t size);
int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
char			*ft_flags(char *str, int *left, char *whidt_c);
char			*ft_precision(char *str, int *prec, va_list argptr);
char			*ft_widht(char *str, t_flag *flag, va_list argptr);
int				ft_printf(const char *str, ...);
void			ft_discriminator(char *str, t_flag *flag, va_list argptr);
void			ft_string(t_flag *flag, va_list argptr);
void			ft_start_up(t_flag	*flag);
void			ft_padding(t_flag *flag);
void			ft_character(t_flag *flag, va_list argptr);
void			ft_write_count(char *str, int len, t_flag *flag);
void			ft_integer(t_flag *flag, va_list argptr, char *base);
char			*ft_itoa_base(long nbr, char *base);
void			ft_hexa(t_flag *flag, va_list argptr, char *base);
void			ft_ptr_address(t_flag *flag, va_list argptr, char *base);
char			*ft_itoa_base_ptr(unsigned long long nbr, char *base);
void			ft_percent(t_flag *flag);

#endif
