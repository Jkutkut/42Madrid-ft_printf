/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:57:28 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/26 13:21:34 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "ft_printf.h"

size_t	ft_put_pointer_fd(unsigned long p, int fd);
size_t	ft_putchar_fd(char s, int fd);
size_t	ft_putstr_fd(char *s, int fd);

#endif