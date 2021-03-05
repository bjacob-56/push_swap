/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:37:29 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 08:37:29 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra(t_swap *swap)
{
	t_nbr*	temp;
	t_nbr	*pre_last;

	if (nbr_size(swap->nbra) > 1)
	{
		temp = ft_nbrlast(swap->nbra);
		pre_last = swap->nbra;
		while (pre_last->next->next)
			pre_last = pre_last->next;
		pre_last->next = NULL;
		ft_addnbr_front(&swap->nbra, temp);
	}
}

void	ft_rrb(t_swap *swap)
{
	t_nbr*	temp;
	t_nbr	*pre_last;

	if (nbr_size(swap->nbrb) > 1)
	{
		temp = ft_nbrlast(swap->nbrb);
		pre_last = swap->nbrb;
		while (pre_last->next->next)
			pre_last = pre_last->next;
		pre_last->next = NULL;
		ft_addnbr_front(&swap->nbrb, temp);
	}
}

void	ft_rrr(t_swap *swap)
{
	ft_rra(swap);
	ft_rrb(swap);
}
