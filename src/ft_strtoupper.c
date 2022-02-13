/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:29:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/13 22:42:57 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_strtoupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
