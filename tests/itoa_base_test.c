/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:34:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/05 22:56:12 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test(long int i, char *base)
{
	char *str;

	str = ft_itoa_base(i, base);
	printf("%li in base \"%s\" : \"%s\"\n", i, base, str);
	free(str);
}

int	main(void)
{
	test(0, "0123456789");
	test(1, "0123456789");
	test(2, "0123456789");
	test(9, "0123456789");
	test(10, "0123456789");
	return (0);
}