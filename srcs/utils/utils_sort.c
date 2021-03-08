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
	int max;

	max = nbr_max(nbr);
	if (nbr_size(nbr) <= 1)
		return (1);
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

void	align_to_top(t_swap *swap)
{
	int maxb;
	int count;
	t_nbr	*nbrb;

	maxb = nbr_max(swap->nbrb);
	count = 0;
	nbrb = swap->nbrb;
	while (nbrb->nb != maxb)
	{
		ft_rb(swap);
		count++;
	}
	print_rotate('b', count, nbr_size(nbrb), swap);
}