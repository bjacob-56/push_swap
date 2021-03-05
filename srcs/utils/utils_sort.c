/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:22:33 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 07:22:33 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_nbr* nbr)
{
	if (!nbr)
		return (1);
	while (nbr->next)
	{
		if (nbr->nb > nbr->next->nb)
			return (0);
		else
			nbr = nbr->next;
	}
	return (1);
}

void	final_check(t_swap *swap)
{
	if (is_sorted(swap->nbra) && !swap->nbrb)
		printf("OK\n");
	else
		printf("KO\n");
}