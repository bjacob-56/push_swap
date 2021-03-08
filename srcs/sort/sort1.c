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

void	apply_rotation(t_swap *swap, int j, char c)
{
	t_nbr *nbr;

	if (c == 'b')
		nbr = swap->nbrb;
	else
		nbr = swap->nbra;
	while (j-- > 0)
	{
		if (swap->print)
			printf("r%c\n", c);
		if (c == 'b')
			ft_rb(swap);
		else
			ft_ra(swap);
		swap->count_sort++;
	}
}


void	insert_topa_in_b(t_swap *swap)
{
	int i;

	t_nbr *temp;
	temp = swap->nbrb;
	i = 0;

	// display_stack(swap);

	while (temp && swap->nbra->nb < temp->nb)
	{
		temp = temp->next;
		i++;
	}
	if (i > nbr_size(swap->nbrb) / 2)
		apply_reverse_rotation(swap, nbr_size(swap->nbrb) - i, 'b');
	else
		apply_rotation(swap, i, 'b'); // a ajuster
	if (swap->print)
		printf("pb\n");
	ft_pb(swap);
}

void	to_min_b(t_swap *swap)
{
	t_nbr	*nbr;

	nbr = swap->nbrb;
	if (nbr_size(nbr) > 1)
	{
		while (nbr->nb < ft_nbrlast(nbr)->nb)
		{
			if (swap->print)
				printf("rb\n");
			ft_rb(swap);
		}
	}
}

void	to_max_b(t_swap *swap)
{
	t_nbr	*nbr;

	nbr = swap->nbrb;
	if (nbr_size(nbr) > 1)
	{
		while (nbr->nb < ft_nbrlast(nbr)->nb)
		{
			if (swap->print)
				printf("rb\n");
			ft_rb(swap);
		}
	}
}

void	sort1(t_swap *swap)
{
	while (!two_sorted_stack_in_order(swap))
	{
		to_max_b(swap);

	display_stack(swap);

		if (nbr_size(swap->nbra) > 1 && swap->nbra->nb > swap->nbra->next->nb)
		{
			if (swap->print)
				printf("sa\n");
			ft_sa(swap);	// utile ?
			swap->count_sort++;
		}
		else
			insert_topa_in_b(swap);
	}
	while (swap->nbrb)
	{
		if (swap->print)
			printf("pa\n");
		ft_pa(swap);
		swap->count_sort++;
	}

	display_stack(swap);
}
