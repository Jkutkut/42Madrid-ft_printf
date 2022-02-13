/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:10:35 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/10 23:11:58 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h> // va_list
#include <stdlib.h> // malloc free
#include <unistd.h> // write
#include <stdio.h> // ! TODO DEBUG

int		ft_printf(const char *, ...);

#endif