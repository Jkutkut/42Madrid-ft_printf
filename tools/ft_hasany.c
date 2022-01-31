/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:03:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/01/31 13:15:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_hasany(const char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}
