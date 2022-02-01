/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:28:19 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 10:46:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include "colors.h"

int	main(void)
{
	printf("%sBasic test:%s\n", TITLE, NC);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	ft_printf("hola caracola\n");
	printf("%s---------------------------------%s\n", YELLOW, NC);
	ft_printf("%s %s %s\n", "hola", "caracola", "que tal?");
	printf("%s---------------------------------%s\n", YELLOW, NC);
	ft_printf("hola caracola\n", "hola", "caracola", 123);
	printf("%s---------------------------------%s\n", YELLOW, NC);
	return (0);
}
