/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:19:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 13:33:19 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_until_format(char **format)
{
	size_t	i;
	char	*str;

	if (format == NULL || *format == NULL)
		return (-1);
	str = *format;
	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	ft_putnstr(str, i);
	str += i;
	return (i);

}

int	ft_format_printf(char *format, va_list lst)
{
	int i;

	i = 0;
	while (*format)
	{
		printf("IN\n");
		if ((i = ft_print_until_format(&format)) < 0 || !*format)
			return (i);
		printf("%s", va_arg(lst, char *));
		break;
	}
	return (i);
}

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
	printf("number of argvs: %i\n", argc);
	printf("Arguments:\n");

	va_start(argv, format);

	// while (argc--)
	// while ((tmp = va_arg(valist, char *)) != NULL)
	// {
	// 	printf("%s\n", tmp);
	// }
	printed = ft_format_printf(format_cpy, argv);
	va_end(argv);
	free(format_cpy);
	// ft_putstr_fd((char *) format, 1);
	
	return (printed);
}
