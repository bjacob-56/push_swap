/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:17:14 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 10:18:34 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

long		ft_atoi(const char *str)
{
	long	res;
	int		signe;

	res = 0;
	signe = 1;
	while (is_white_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signe = -signe;
	}
	while (ft_isdigit((int)*str))
	{
		res = 10 * res + (*str++ - '0');
		if (signe * res < INT_MIN || signe * res > INT_MAX)
			return ((long)INT_MAX + 1);
	}
	return (signe * res);
}
