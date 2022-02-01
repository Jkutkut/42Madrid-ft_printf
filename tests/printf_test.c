/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:13:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 09:45:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	printf("Test ft_printf\n");
	printf("Test ft_printf with %s\n", "NULL");
	printf("Test ft_printf with %s\n", "hola que tal");
	printf("Test ft_printf with %s\n", "");
	printf("Test ft_printf with %s\n", NULL);
	printf("Test ft_printf with %s\n", "hola%iquetal");
	printf("Test ft_printf with %s\n", "%c start");
	printf("Test ft_printf with %s\n", "end %s");
	printf("Test ft_printf with %s\n", "%s start and end %i");
	printf("Test ft_printf with %s\n", "percent %% percent");
	printf("Test ft_printf with %s\n", "%s start, percent %% and end %i");
	printf("Test ft_printf with %s\n", "%%");
	printf("Test ft_printf with %s\n", "%% %s");
	printf("Test ft_printf with %s\n", "%% %s %i");
	printf("Test ft_printf with %s\n", "%% %s %i %c");
	printf("Test ft_printf with %s\n", "%% %s %i %c %s");

	printf("\nTest ft_printf with invalid tests\n");
	printf("%%%i%q");
}