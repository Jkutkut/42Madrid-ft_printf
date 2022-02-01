/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argc_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:05:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 09:18:23 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#define TEST_L 31

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
	printf("\n\033[1;33mTest ft_get_argc\n\033[0m");
	test("hola que tal", 0);
	test("", 0);
	test(NULL, 0);
	test("hola%iquetal", 1);
	test("%c start", 1);
	test("end %s", 1);
	test("%s start and end %i", 2);
	test("percent %% percent", 1);
	test("%s start, percent %% and end %i", 3);

	printf("\n\033[1;33mTest ft_get_argc with conversions\n\033[0m");
	test("%c", 1);
	test("%s", 1);
	test("%p", 1);
	test("%d", 1);
	test("%i", 1);
	test("%u", 1);
	test("%x", 1);
	test("%X", 1);
	test("%%", 1);

	test("%a", 0);
	test("%b", 0);
	test("%d", 0);
	test("%e", 0);
}

