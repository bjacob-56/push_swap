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

void	apply_reverse_rotation(t_swap *swap, int j, char c))
{
	t_nbr *nbr;

	if (c == 'b')
		nbr = swap->nbrb;
	else
		nbr = swap->nbra;
	while (j-- > 0)
	{
		printf("rr%c\n", c);
		ft_rrb(nbr);		
	}
}

void	apply_rotation(t_swap *swap, int j, char c))
{
	t_nbr *nbr;

	if (c == 'b')
		nbr = swap->nbrb;
	else
		nbr = swap->nbra;
	while (j-- > 0)
	{
		printf("r%c\n", c);
		ft_rb(nbr);		
	}
}


void	insert_topa_in_b(t_swap *swap)
{
	int i;


	t_nbr *temp;

	temp = swap->nbrb;
	i = 0;
	while (temp && swap->nbra->nb > temp->nb)
	{
		temp = temp->next;
		i++;
	}
	if (i > nbr_size(swap->nbrb) / 2)
		apply_reverse_rotation(swap->nbrb, nbr_size(swap->nbrb - i));
	else
		apply_rotation(swap->nbrb, i);
	ft_pb(swap);
}

void	sort(t_swap *swap)
{
	while (!two_sorted_stack_in_order(swap))
	{
		if (swap->nbra->nb > swap->nbra->next->nb)
		{
			printf("sa\n");
			ft_sa(swap);
		}	
		else
			insert_topa_in_b(swap);
	}
}

// reste a remettre tout dans a