/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:59:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/05 22:51:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_nbrlen(size_t n, size_t base_len)

char	*ft_super_itoa(long int n)
{
	size_t	order;
	char	d;
	char	*str;

	order = ft_nbrlen(n, 10);
	str = (char *) malloc(sizeof(char) * (order + 1));
	if (str == NULL)
		return (str);
	str[order] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[--order] = '0';
	while (n != 0)
	{
		d = n % 10;
		if (d < 0)
			d = -d;
		str[--order] = d + '0';
		n /= 10;
	}
	return (str);
}
