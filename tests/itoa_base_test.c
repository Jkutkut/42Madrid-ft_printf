/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:34:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/06 00:16:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test(long int i, char *base)
{
	char *str;

	str = ft_itoa_base(i, base);
	printf("Base \"%s\" %li: \"%s\"\n", base, i, str);
	free(str);
}

int	main(void)
{
	test(0, "0123456789");
	test(1, "0123456789");
	test(9, "0123456789");
	test(10, "0123456789");
	test(-1, "0123456789");
	test(-10, "0123456789");

	test(0, "0123456789abcdef");
	test(1, "0123456789abcdef");
	test(9, "0123456789abcdef");
	test(10, "0123456789abcdef");
	test(15, "0123456789abcdef");
	test(16, "0123456789abcdef");
	test(-1, "0123456789abcdef");
	test(-10, "0123456789abcdef");
	test(-15, "0123456789abcdef");
	test(-16, "0123456789abcdef");

	test(0, "01");
	test(1, "01");
	test(9, "01");
	test(10, "01");
	test(15, "01");
	test(16, "01");
	test(-1, "01");
	test(-10, "01");
	test(-15, "01");
	test(-16, "01");
	return (0);
}