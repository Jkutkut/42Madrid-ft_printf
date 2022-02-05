/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:41:50 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/05 22:47:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_nbrlen(size_t n, size_t base_len)
{
	size_t	order;

	if (!base_len)
		return (0);
	if (!n)
		return (1);
	order = 0;
	if (n < 0)
		order++;
	while (n != 0)
	{
		order++;
		n /= base_len;
	}
	return (order);
}