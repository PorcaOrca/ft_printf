/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:03:13 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/31 16:08:34 by lspazzin         ###   ########.fr       */
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

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
int				ft_atoi(char *str);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *str1, char const *str2);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *str, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putstr_fd(char *str, int fd);
char			*ft_strjoin(char const *str1, char const *str2);
char			*ft_strtrim(char const *str, char const *set);
char			**ft_split(char const *str, char c);
char			*ft_itoa(int nbr);
char			*ft_strmapi(char const *s, char (*fct)(unsigned int, char));
void			ft_putnbr_fd(int nbr, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));

char			*ft_flags(char *str, int *left, char *whidt_c);
char			*ft_precision(char *str, int *prec, va_list argptr);
char			*ft_widht(char *str, int *pad, va_list argptr);
int				ft_printf(const char *str, ...);
void			ft_discriminator(char *str, t_flag *flag, va_list argptr);
void			ft_string(t_flag *flag, va_list argptr);
void			ft_start_up(t_flag	*flag);
void			ft_padding(t_flag *flag);
void			ft_character(t_flag *flag, va_list argptr);
void			ft_write_count(char *str, int len, t_flag *flag);
void			ft_integer(t_flag *flag, va_list argptr);
char			*ft_itoa_base(long nbr, char *base);
void	ft_hexa(t_flag *flag, va_list argptr, char *base);

#endif
