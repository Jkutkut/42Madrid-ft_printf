/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:19:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/02 16:50:20 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_argv(char **format, va_list lst)
{
	int	i;
	char	*str;

	i = -1;
	if (ft_strncmp(*format, "%s", 2) == 0)
	{
		*format += 2;
		str = va_arg(lst, char *);
		i = ft_strlen(str);
		ft_putnstr(str, i);
	}
	else if (ft_strncmp(*format, "%c", 2) == 0)
	{
		*format += 2;
		i = 1;
		ft_putchar_fd(va_arg(lst, int), 1);
	}
	else if (ft_strncmp(*format, "%i", 2))
	{
		*format += 2;
		str = ft_itoa(va_arg(lst, int));
		ft_putstr_fd(str, 1);
		free(str);
	}
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
		if (j < 0)
			return (i);
		i += j;
		if (*format == '\0')
			return (i);
		j = ft_print_argv(&format, lst);
		if (j < 0)
		{
			ft_putstr_fd("not implemented", 15);
			break;
		}
		i += j;
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
