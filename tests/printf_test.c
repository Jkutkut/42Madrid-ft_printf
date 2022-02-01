/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:13:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 09:15:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	printf("Test ft_printf");
	printf("Test ft_printf with %s", "NULL");
	printf("Test ft_printf with %s", "hola que tal");
	printf("Test ft_printf with %s", "");
	printf("Test ft_printf with %s", NULL);
	printf("Test ft_printf with %s", "hola%iquetal");
	printf("Test ft_printf with %s", "%c start");
	printf("Test ft_printf with %s", "end %s");
	printf("Test ft_printf with %s", "%s start and end %i");
	printf("Test ft_printf with %s", "percent %% percent");
	printf("Test ft_printf with %s", "%s start, percent %% and end %i");
	printf("Test ft_printf with %s", "%%");
	printf("Test ft_printf with %s", "%% %s");
	printf("Test ft_printf with %s", "%% %s %i");
	printf("Test ft_printf with %s", "%% %s %i %c");
	printf("Test ft_printf with %s", "%% %s %i %c %s");
}