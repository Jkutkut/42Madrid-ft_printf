/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argc_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:05:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/26 12:38:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "libft.h"

#define TEST_1_L 31
#define TEST_2_L 2

void	test(const char *str, int spected, const int TEST_L)
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

void	test1(const char *str, int spected)
{
	test(str, spected, TEST_1_L);
}

void	test2(const char *str, int spected)
{
	test(str, spected, TEST_2_L);
}

int	main(void)
{
	printf("\n\033[1;33mTest ft_get_argc\n\033[0m");
	test1("hola que tal", 0);
	test1("", 0);
	test1(NULL, 0);
	test1("hola%iquetal", 1);
	test1("%c start", 1);
	test1("end %s", 1);
	test1("%s start and end %i", 2);
	test1("percent %% percent", 1);
	test1("%s start, percent %% and end %i", 3);

	printf("\n\033[1;33mTest ft_get_argc with conversions\n\033[0m");
	test2("%c", 1);
	test2("%s", 1);
	test2("%p", 1);
	test2("%d", 1);
	test2("%i", 1);
	test2("%u", 1);
	test2("%x", 1);
	test2("%X", 1);
	test2("%%", 1);

	test2("%a", 0);
	test2("%b", 0);
	test2("%e", 0);
	test2("%f", 0);

	// Print a message in green
	printf("\nAll tests \033[0;32mOK\n\033[0m");
}

