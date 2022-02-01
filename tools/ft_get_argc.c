/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_argc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:19:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/01 09:25:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define VALID_CONV "cspdiuxX%"

int	ft_get_argc(const char *format)
{
	size_t	i;
	int		c;

	if (format == NULL)
		return (0);
	i = 0;
	c = 0;
	while (format[i])
	{
		if (ft_hasany(FLAGS_CONV, format[i]) &&
			format[i + 1] && ft_hasany(VALID_CONV, format[i + 1]))
		{
			c++;
			i++;
		}
		i++;
	}
	return (c);
}

