/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:21:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/01/31 10:16:40 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS_CONV "%"
//# define FLAGS_CONV "%# +"
# define FLAG_MIN_W ".-O"

int		ft_printf(const char *, ...);
int	ft_get_argv(const char format);

#endif

