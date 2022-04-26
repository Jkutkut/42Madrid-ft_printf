/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:07:03 by jkutkut           #+#    #+#             */
/*   Updated: 2022/04/26 12:26:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int fd, char type, va_list lst)
{
	char	*str;
	int		i;

	if (type == 'u')
		str = ft_itoa_base(va_arg(lst, unsigned int), DECIMAL);
	else if (ft_hasany("Xx", type))
	{
		str = ft_itoa_base(va_arg(lst, unsigned int), HEXADECIMAL);
		if (type == 'X')
			ft_strtoupper(str);
	}
	else
		str = ft_itoa_base(va_arg(lst, int), DECIMAL);
	i = ft_putstr_fd(str, fd);
	free(str);
	return (i);
}

int	ft_print_argv(int fd, char **format, va_list lst)
{
	int		i;

	if (*++(*format) == 'c')
		i = ft_putchar_fd(va_arg(lst, int), fd);
	else if (**format == 's')
		i = ft_putstr_fd(va_arg(lst, char *), fd);
	else if (**format == 'p')
		i = ft_put_pointer_fd(va_arg(lst, unsigned long), fd);
	else if (ft_hasany("iduxX", **format))
		i = ft_print_number(fd, **format, lst);
	else
		i = ft_putchar_fd('%', fd);
	(*format)++;
	return (i);
}

int	ft_print_until_format(int fd, char **format)
{
	int		i;
	char	*str;

	if (format == NULL || *format == NULL)
		return (-1);
	str = *format;
	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(fd, str, i);
	*format += i;
	return (i);
}

int	ft_format_printf(int fd, char *format, va_list lst)
{
	int	i;
	int	j;

	i = 0;
	while (*format)
	{
		j = ft_print_until_format(fd, &format);
		if (j < 0)
			return (i);
		i += j;
		if (*format == '\0')
			return (i);
		i += ft_print_argv(fd, &format, lst);
	}
	return (i);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	argv;
	int		printed;
	char	*format_cpy;

	if (format == NULL)
		return (-1);
	format_cpy = ft_strdup(format);
	va_start(argv, format);
	printed = ft_format_printf(fd, format_cpy, argv);
	va_end(argv);
	free(format_cpy);
	return (printed);
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
	printed = ft_format_printf(FD, format_cpy, argv);
	va_end(argv);
	free(format_cpy);
	return (printed);
}
