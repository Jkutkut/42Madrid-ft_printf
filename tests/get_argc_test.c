/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argc_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:05:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/01/31 11:15:42 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	test(const char *str, int spected)
{
	int	result;

	printf("Test: \"%s\" -> ", str);
	result = ft_get_argv(str);

	if (result == spected)
		printf("OK");
	else
	{
		printf("KO!");
		exit(0);
	}
}

int	main(void)
{
	test("hola que tal", 0);
	test("", 0);
	test(NULL, 0);
}

