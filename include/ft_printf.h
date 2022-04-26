/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:10:35 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/26 12:07:04 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_list
# include <stdlib.h> // malloc free
# include <unistd.h> // write

# define STDOUT 1

# ifndef FD
#  define FD STDOUT
# endif

# define DECIMAL "0123456789"
# define HEXADECIMAL "0123456789abcdef"

int		ft_hasany(const char *str, char c);
char	*ft_itoa_base(ssize_t nbr, char *base);
size_t	ft_nbrlen(ssize_t n, ssize_t base_len);
int		ft_printf(const char *format, ...);
size_t	ft_put_pointer_fd(unsigned long p, int fd);
size_t	ft_putchar_fd(char s, int fd);
size_t	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strtoupper(char *str);

#endif