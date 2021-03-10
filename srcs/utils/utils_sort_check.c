/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:46:52 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 08:47:46 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		is_sorted(t_nbr *nbr)
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

int		is_sorted_reverse(t_nbr *nbr)
{
	int max;

	max = nbr_max(nbr);
	if (nbr_size(nbr) <= 1)
		return (1);
	if (ft_nbrlast(nbr)->nb < nbr->nb && nbr->nb != max)
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

int		a_almost_empty_and_b_sorted(t_swap *swap)
{
	if (nbr_size(swap->nbra) <= 2 &&
		is_sorted_reverse(swap->nbrb))
		return (1);
	return (0);
}

void	final_check(t_swap *swap)
{
	if (is_sorted(swap->nbra) && !swap->nbrb &&
		swap->nbra->nb == nbr_min(swap->nbra))
		printf("OK\n");
	else
		printf("KO\n");
}
