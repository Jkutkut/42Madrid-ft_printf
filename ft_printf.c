/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:19:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/01/31 10:15:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_get_argv(const char format)
{
	size_t	i
	int		c;

	i = 0;
	c = 0;
	while (format[i])
	{
		if (ft_hasany(FLAGS_CONV, format[i]))
			c++;
		i++;
	}
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	int		argc;

	argv = ft_get_argv(format);
	ft_putstr_fd((char *) format, 1);
	
	printf("number of argv: %i", argc);
	
	return (0);
}
