/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:19:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/01/31 13:52:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	int		argc;

	argc = ft_get_argc(format);
	ft_putstr_fd((char *) format, 1);
	
	printf("number of argv: %i", argc);
	
	return (0);
}
