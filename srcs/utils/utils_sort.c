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

int	is_sorted_reverse(t_nbr* nbr)
{
	if (!nbr)
		return (1);
	while (nbr->next)
	{
		if (nbr->nb < nbr->next->nb)
			return (0);
		else
			nbr = nbr->next;
	}
	return (1);
}

int	two_sorted_stack_in_order(t_swap *swap)
{
	if (is_sorted(swap->nbra) &&
		is_sorted_reverse(swap->nbrb) &&
		swap->nbra->nb > swap->nbrb->nb)
		return (1);
	return (0);
}

void	final_check(t_swap *swap)
{
	if (is_sorted(swap->nbra) && !swap->nbrb)
		printf("OK\n");
	else
		printf("KO\n");
}