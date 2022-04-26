/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:57:28 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/26 13:20:47 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "ft_printf.h"

int		ft_hasany(const char *str, char c);
char	*ft_itoa_base(ssize_t nbr, char *base);
size_t	ft_nbrlen(ssize_t n, ssize_t base_len);

#endif