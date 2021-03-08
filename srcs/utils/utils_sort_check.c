/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:11:18 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/08 15:11:18 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_nbr* nbr)
{
	int max;

	max = nbr_max(nbr);
	if (nbr_size(nbr) <= 1)
		return (1);
	if (ft_nbrlast(nbr)->nb > nbr->nb && ft_nbrlast(nbr)->nb != max)
		return (0);
	while (nbr->next)
	{
		if (nbr->nb > nbr->next->nb && nbr->nb != max)
			return (0);
		else
			nbr = nbr->next;
	}

	return (1);
}

int	is_sorted_reverse(t_nbr* nbr)
{
	int max;

	max = nbr_max(nbr);
	if (nbr_size(nbr) <= 1)
		return (1);
	if (ft_nbrlast(nbr)->nb < nbr->nb && nbr->nb != max) // a verifier
		return (0);
	while (nbr->next)
	{
		if (nbr->nb < nbr->next->nb && nbr->next->nb != max)
			return (0);
		else
			nbr = nbr->next;
	}
	return (1);
}

int	a_empty_and_b_sorted(t_swap *swap)
{
	if (!swap->nbra &&
		is_sorted_reverse(swap->nbrb))
		return (1);
	return (0);
}

void	final_check(t_swap *swap) // utiliser checker ici
{
	if (is_sorted(swap->nbra) && !swap->nbrb)
		printf("OK\n");
	else
		printf("KO\n");
}