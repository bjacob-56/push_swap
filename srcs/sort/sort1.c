/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:21:22 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 10:21:22 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	apply_reverse_rotation(t_swap *swap, int j, char c)
{
	t_nbr *nbr;

	if (c == 'b')
		nbr = swap->nbrb;
	else
		nbr = swap->nbra;
	while (j-- > 0)
	{
		if (swap->print)
			printf("rr%c\n", c);
		ft_rrb(swap);
		swap->count_sort++;	
	}
}

void	insert_topa_in_b(t_swap *swap)
{
	int i;
	int	nba;
	int	maxb;
	int	minb;
	
	nba = swap->nbra->nb;
	i = 0;
	if (nbr_size(swap->nbrb) > 1)
	{
		maxb = nbr_max(swap->nbrb);
		minb = nbr_min(swap->nbrb);
		while(!(nba < ft_nbrlast(swap->nbrb)->nb && nba > swap->nbrb->nb) &&
			!(nba > maxb && swap->nbrb->nb == maxb) &&
			!(nba < minb && swap->nbrb->nb == maxb))
		{
			ft_rb(swap);
			i++;
		}
		print_rotate('b', i, nbr_size(swap->nbrb), swap);
	}
	ft_pb(swap);
	swap->count_sort++;
}

void	sort1(t_swap *swap)
{
	while (!a_empty_and_b_sorted(swap))
	{
		display_stack(swap);	// display

		insert_topa_in_b(swap);
	}
	align_to_top(swap);
	while (swap->nbrb)
	{
		ft_pa(swap);
		swap->count_sort++;
	}

	display_stack(swap);
}
