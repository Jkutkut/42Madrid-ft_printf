/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:19:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 13:55:04 by jre-gonz         ###   ########.fr       */
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
	*format += i;
	return (i);

}

int	ft_format_printf(char *format, va_list lst)
{
	int i;
	int j;

	i = 0;
	while (*format)
	{
		j = ft_print_until_format(&format);
		if (j <= 0)
			return (i);
		i += j;
		if (*format == '\0')
			return (i);
		printf("%s", va_arg(lst, char *));
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
	printf("- format: \"%s\"\n- Number of argvs: %i\n\n", format, argc);
	va_start(argv, format);
	printed = ft_format_printf(format_cpy, argv);
	va_end(argv);
	free(format_cpy);
	return (printed);
}
