/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:07:03 by jkutkut           #+#    #+#             */
/*   Updated: 2022/02/13 21:19:11 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DECIMAL "0123456789"
#define HEXADECIMAL "0123456789abcdef"

size_t	ft_nbrlenv2(unsigned long long int n, ssize_t base_len)
{
	size_t	order;

	if (base_len <= 0)
		return (0);
	if (!n)
		return (1);
	order = 0;
	// if (n < 0)
	// 	order++;
	while (n != 0)
	{
		order++;
		n /= base_len;
	}
	return (order);
}

char	*ft_itoa_basev2(unsigned long long int nbr, char *base)
{
	ssize_t	b_len;
	size_t	order;
	char	*str;
	char	sign;

	b_len = ft_strlen(base);
	order = ft_nbrlenv2(nbr, b_len);
	str = (char *) malloc(sizeof(char) * (order + 1));
	if (str == NULL)
		return (str);
	str[order--] = '\0';
	sign = 1;
	// if (nbr < 0)
	// {
	// 	sign = -1;
	// 	str[0] = '-';
	// }
	if (nbr == 0)
		str[order] = '0';
	while (nbr != 0)
	{
		str[order--] = base[((ssize_t) nbr % b_len) * sign];
		nbr /= b_len;
	}
	return (str);
}

int	ft_print_argv(char **format, va_list lst)
{
	int		i;
	char	*str;

	i = -1;
	if (ft_strncmp(*format, "%c", 2) == 0)
		i = ft_putchar_fd(va_arg(lst, int), 1);
	else if (ft_strncmp(*format, "%s", 2) == 0)
		i = ft_putstr_fd(va_arg(lst, char *), 1);
	else if (ft_strncmp(*format, "%p", 2) == 0)
	{
		str = ft_itoa_basev2(va_arg(lst, unsigned long long), HEXADECIMAL);
		if (*str == '0')
			i = ft_putstr_fd("(nil)", 1);
		else
		{
			i = ft_putstr_fd("0x", 1);
			// if (*str == '-')
			// 	i += ft_putstr_fd(str + 1, 1);
			// else
			i += ft_putstr_fd(str, 1);
		}		
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
		str = ft_itoa_base(va_arg(lst, unsigned int), DECIMAL);
		i = ft_putstr_fd(str, 1);
		free(str);
	}
	else if (ft_strncmp(*format, "%%", 2) == 0)
	{
		i = ft_putchar_fd('%', 1);
	}
	else // %x %X
	{
		str = ft_itoa_base(va_arg(lst, unsigned int), HEXADECIMAL);
		if (ft_strncmp(*format, "%X", 2) == 0)
		{
			size_t	j;

			j = 0;
			while (str[j])
			{
				str[j] = ft_toupper(str[j]);
				j++;
			}
		}
		i = ft_putstr_fd(str, 1);
		free(str);
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
			ft_putstr_fd("not implemented\n", 1);
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