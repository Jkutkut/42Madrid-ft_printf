/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:28:19 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/13 21:05:06 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"
#include <limits.h>
#include "colors.h"

int	main(void)
{
	printf("%sBasic test:%s\n", TITLE, NC);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	ft_printf("hola caracola\n");
	printf("%s---------------------------------%s\n", YELLOW, NC);
	ft_printf("%s %s %s\n", "hola", "caracola", "que tal?");
	printf("%s---------------------------------%s\n", YELLOW, NC);
	ft_printf("%c%c%c%c\n", 'h', 'o', 'l', 'a');
	printf("%s---------------------------------%s\n", YELLOW, NC);
	ft_printf("%i%c%i%c\n", 104, 'o', -108, 'a');
	printf("%s---------------------------------%s\n", YELLOW, NC);
	ft_printf("%d %d %d %d %d\n", 100, 100, 256, -1, -123);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	char *str1 = "hola";
	char *str2 = "hola que tal";
	char *str3 = "hola que tal estas";
	printf("%p %p %p\n", str1, str2, str3);
	ft_printf("%p %p %p\n", str1, str2, str3);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	printf("%p -- ", (void *) 0);
	fflush(stdout);
	ft_printf("%p\n", 0);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	printf("%p %p\n", (void *) LONG_MIN, (void *) LONG_MAX);
	ft_printf("%p %p\n", LONG_MIN, LONG_MAX);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	printf("%p %p\n", (void *) ULONG_MAX, (void *) -ULONG_MAX);
	ft_printf("%p %p\n", ULONG_MAX, -ULONG_MAX);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	printf("%x %x %x\n", 0, 1, -1);
	ft_printf("%x %x %x\n", 0, 1, -1);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	printf("%x %x %x\n", (unsigned int) LONG_MAX, (unsigned int) LONG_MIN, (unsigned int) ULONG_MAX);
	ft_printf("%x %x %x\n", LONG_MAX, LONG_MIN, ULONG_MAX);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	return (0);
}
