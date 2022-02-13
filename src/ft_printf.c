/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:07:03 by jkutkut           #+#    #+#             */
/*   Updated: 2022/02/13 17:03:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DECIMAL "0123456789"
#define HEXADECIMAL "0123456789abcdef"

int	ft_print_argv(char **format, va_list lst)
{
	int	i;
	char	*str;

	i = -1;
	if (ft_strncmp(*format, "%c", 2) == 0)
	{
		i = 1;
		ft_putchar_fd(va_arg(lst, int), 1);
	}
	else if (ft_strncmp(*format, "%s", 2) == 0)
	{
		i = ft_putstr_fd(va_arg(lst, char *), 1);
	}
	else if (ft_strncmp(*format, "%p", 2) == 0)
	{
		str = ft_itoa_base(va_arg(lst, ssize_t), HEXADECIMAL);
		i = ft_strlen(str) + 2;
		write(1, "0x", 2);
		write(1, str, i);
		free(str);
	}
	else if (!ft_strncmp(*format, "%d", 2) || !ft_strncmp(*format, "%i", 2))
	{
		str = ft_itoa_base(va_arg(lst, int), DECIMAL);
		i = ft_putstr_fd(str, 1);
		free(str);
	}
	else if (ft_strncmp(*format, "%u", 2) == 0)
	{
		*format += 2;
		str = ft_itoa_base(va_arg(lst, unsigned long), DECIMAL);
		ft_putstr_fd(str, 1);
		i = ft_strlen(str);
		free(str);
	}
	else if (ft_strncmp(*format, "%%", 2) == 0)
	{
		*format += 2;
		i += 1;
		ft_putchar_fd('%', 1);
	}
	else // %x %X
	{
		*format += 2;
		str = ft_itoa_base(va_arg(lst, unsigned long), HEXADECIMAL);
		i = ft_strlen(str) + 2;
		write(1, "0x", 2);
		if (ft_strncmp(*(format - 1), "X", 2) == 0)
		{
			size_t	j;

			j = 0;
			while (str[j])
			{
				str[j] = ft_toupper(str[j]);
				j++;
			}
		}
	}
	*format += 2;
	
	return (i);
}

int	ft_print_until_format(char **format)
{
	int	i;
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
	int i;
	int j;

	i = 0;
	while (*format)
	{
		j = ft_print_until_format(&format);
		if (j < 0)
			return (i);
		i += j;
		if (*format == '\0')
			return (i);
		j = ft_print_argv(&format, lst);
		if (j < 0)
		{
			ft_putstr_fd("not implemented", 1);
			break;
		}
		i += j;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	argv;
	// int		argc;
	int		printed;
	char	*format_cpy;

	if (format == NULL)
		return (-1);
	format_cpy = ft_strdup(format);
	// argc = ft_get_argc(format_cpy);
	// printf("- format: \"%s\"\n- Number of argvs: %i\n\n", format, argc);
	va_start(argv, format);
	printed = ft_format_printf(format_cpy, argv);
	va_end(argv);
	free(format_cpy);
	return (printed);
}