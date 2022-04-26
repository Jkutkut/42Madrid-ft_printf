/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:57:28 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/26 13:52:10 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "ft_printf.h"

int		ft_format_printf(int fd, char *format, va_list lst);
int		ft_print_argv(int fd, char **format, va_list lst);
int		ft_print_number(int fd, char type, va_list lst);
int		ft_print_until_format(int fd, char **format);
size_t	ft_put_pointer_fd(unsigned long p, int fd);
size_t	ft_putchar_fd(char s, int fd);
size_t	ft_putstr_fd(char *s, int fd);

#endif