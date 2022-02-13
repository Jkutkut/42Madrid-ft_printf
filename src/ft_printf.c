/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:07:03 by jkutkut           #+#    #+#             */
/*   Updated: 2022/02/13 23:05:24 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_argv(char **format, va_list lst)
{
	int		i;
	char	*str;

	if (*++(*format) == 'c')
		i = ft_putchar_fd(va_arg(lst, int), 1);
	else if (**format == 's')
		i = ft_putstr_fd(va_arg(lst, char *), 1);
	else if (**format == 'p')
		i = ft_put_pointer_fd(va_arg(lst, unsigned long), 1);
	else if (ft_hasany("idu", **format))
	{
		if (**format == 'u')
			str = ft_itoa_base(va_arg(lst, unsigned int), DECIMAL);
		else
			str = ft_itoa_base(va_arg(lst, int), DECIMAL);
		i = ft_putstr_fd(str, 1);
		free(str);
	}
	else if (**format == '%')
		i = ft_putchar_fd('%', 1);
	else
	{
		str = ft_itoa_base(va_arg(lst, unsigned int), HEXADECIMAL);
		if (**format == 'X')
			ft_strtoupper(str);
		i = ft_putstr_fd(str, 1);
		free(str);
	}
	(*format)++;
	return (i);
}

int	ft_print_until_format(char **format)
{
	int		i;
	char	*str;

	if (format == NULL || *format == NULL)
		return (-1);
	str = *format;
	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	*format += i;
	return (i);
}

int	ft_format_printf(char *format, va_list lst)
{
	int	i;
	int	j;

	i = 0;
	while (*format)
	{
		j = ft_print_until_format(&format);
		if (j < 0)
			return (i);
		i += j;
		if (*format == '\0')
			return (i);
		i += ft_print_argv(&format, lst);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	argv;
	int		printed;
	char	*format_cpy;

	if (format == NULL)
		return (-1);
	format_cpy = ft_strdup(format);
	va_start(argv, format);
	printed = ft_format_printf(format_cpy, argv);
	va_end(argv);
	free(format_cpy);
	return (printed);
}
