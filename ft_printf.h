/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:21:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/05 23:33:56 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // ! TODO DEBUG

#include "libft.h"

# define FLAGS_CONV "%"
//# define FLAGS_CONV "%# +"
# define FLAG_MIN_W ".-O"

int		ft_printf(const char *, ...);
int		ft_get_argc(const char *format);

// Tools
// int	ft_get_argc(const char *format);
int		ft_hasany(const char *str, const char c);
char	*ft_itoa_base(ssize_t nbr, char *base);
size_t	ft_nbrlen(ssize_t n, size_t base_len);
void	ft_putnstr(const char *str, int n);

#endif

