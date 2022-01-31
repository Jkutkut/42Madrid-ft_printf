/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argc_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:05:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/01/31 13:39:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#define TEST_L 30

void	test(const char *str, int spected)
{
	int		result;
	size_t	l;

	if (str != NULL)
		l = TEST_L - ft_strlen(str);
	else
		l = TEST_L - ft_strlen("(NULL)");
	printf("Test: ");
	while (l--)
		printf(" ");
	printf("\"%s\" -> ", str);
	result = ft_get_argc(str);

	if (result == spected)
		printf("\033[0;32mOK\n\033[0m");
	else
	{
		printf("\033[0;31mKO!\n\033[0m");
		exit(0);
	}
}

int	main(void)
{
	test("hola que tal", 0);
	test("", 0);
	test(NULL, 0);
}

