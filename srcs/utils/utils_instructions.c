/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:46:18 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 08:46:22 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_instruction(char *str, t_swap *swap)
{
	int i;

	i = -1;
	while (++i < NB_INSTRUCTIONS)
		if (!ft_strncmp(str, swap->default_inst[i],
			ft_strlen(swap->default_inst[i]) + 1))
			return (1);
	return (0);
}
