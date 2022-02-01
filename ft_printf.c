/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:19:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 12:29:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_until_format(const char **format)
{
	size_t i;

	if (!*format)
		return (-1);
	i = 0;
	while (*format[i] && *format[i] != '%')
		i++;
	ft_putnstr(*format, i);
	return (i);

}

int	ft_format_printf(const char *format, va_list lst)
{
	int i;

	i = 0;
	while (*format)
	{
		if ((i = ft_print_until_format(&format)) < 0 || !*format)
			return (i);
		break;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	argv;
	int		argc;
	int		printed;
	// char	*tmp;

	argc = ft_get_argc(format);
	printf("number of argvs: %i\n", argc);
	printf("Arguments:\n");

	va_start(argv, format);

	// while (argc--)
	// while ((tmp = va_arg(valist, char *)) != NULL)
	// {
	// 	printf("%s\n", tmp);
	// }
	printed = ft_format_printf(format, argv);
	va_end(argv);
	// ft_putstr_fd((char *) format, 1);
	
	return (printed);
}
