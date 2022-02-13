/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:07:03 by jkutkut           #+#    #+#             */
/*   Updated: 2022/02/13 14:55:55 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	argv;
	int		argc;
	int		printed;
	char	*format_cpy;

	if (format == NULL)
		return (-1);
	format_cpy = ft_strdup(format);
	argc = ft_get_argc(format_cpy);
	printf("- format: \"%s\"\n- Number of argvs: %i\n\n", format, argc);
	va_start(argv, format);
	printed = ft_format_printf(format_cpy, argv);
	va_end(argv);
	free(format_cpy);
	return (printed);
}