/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:46:30 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 08:46:35 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_word_fulldigit(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}
