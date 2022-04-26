/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_full_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:13:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/26 12:38:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "libft.h"

int	main(void)
{
	printf("%c\n", 'a');
	printf("%10c\n", 'a');
	printf("%0c\n", 'a');

	printf("%-c\n", 'a');
	printf("%0c\n", 'a');
	printf("%.c\n", 'a');

	printf("%-2c\n", 'a');
	printf("%-0c\n", 'a');
	printf("%-0c\n", 'a');

}