/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:13:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/03 17:01:10 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	printf("-%20s-\n", "hola caracola");
	printf("-%-20s-\n", "hola caracola");
	printf("-%20.2s-\n", "hola caracola");

	printf("-%5c-\n", 'h');
	printf("-%-2c-\n", 'h');
	printf("-%-2c-\n", 'h');

	printf("-%-20p-\n", "hola");
	printf("-%p-\n", "hola");

	printf("-%i-\n", 123);
	printf("-% 020i-\n", 123);
	printf("-%+020i-\n", 123);
	printf("-%+020i-\n", -123);
	printf("-%-20.2i-\n", 123);
	printf("-%-1.2i-\n", 123);

	
}