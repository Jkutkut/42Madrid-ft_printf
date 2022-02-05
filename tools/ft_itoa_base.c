/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:38:02 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/05 22:55:00 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
size_t	ft_nbrlen(size_t n, size_t base_len);

char	*ft_itoa_base(size_t i, char *base)
{
	size_t	b_len;
	size_t	order;

	b_len = ft_strlen(base);
	order = ft_nbrlen(i, b_len);
}