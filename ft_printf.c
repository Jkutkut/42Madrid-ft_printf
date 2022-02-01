/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:19:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 10:46:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	int		argc;
	char	*tmp;

	argc = ft_get_argc(format);
	printf("number of argv: %i\n", argc);
	printf("Arguments:\n");

	va_start(valist, format);

	// while (argc--)
	while ((tmp = va_arg(valist, char *)) != NULL)
	{
		printf("%s\n", tmp);
	}
	va_end(valist);
	// ft_putstr_fd((char *) format, 1);
	
	return (0);
}
