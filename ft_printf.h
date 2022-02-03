/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:21:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/03 13:03:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h> // ! TODO DEBUG

# define FLAGS_CONV "%"
//# define FLAGS_CONV "%# +"
# define FLAG_MIN_W ".-O"

int		ft_printf(const char *, ...);
int		ft_get_argc(const char *format);

// Tools
int		ft_hasany(const char *str, const char c);
void	ft_putnstr(const char *str, int n);
char	*ft_super_itoa(long int n);

#endif

