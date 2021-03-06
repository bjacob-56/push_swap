/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:43:35 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 08:43:39 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_swap *swap)
{
	int		temp;
	t_nbr	*nbr;

	nbr = swap->nbra;
	if (nbr_size(nbr) > 1)
	{
		temp = nbr->nb;
		nbr->nb = nbr->next->nb;
		nbr->next->nb = temp;
	}
	if (swap->print)
		printf("sa\n");
	swap->count_sort++;
}

void	ft_sb(t_swap *swap)
{
	int		temp;
	t_nbr	*nbr;

	nbr = swap->nbrb;
	if (nbr_size(nbr) > 1)
	{
		temp = nbr->nb;
		nbr->nb = nbr->next->nb;
		nbr->next->nb = temp;
	}
	if (swap->print)
		printf("sb\n");
	swap->count_sort++;
}

void	ft_ss(t_swap *swap)
{
	ft_sa(swap);
	ft_sb(swap);
}

void	ft_pa(t_swap *swap)
{
	t_nbr	*temp;

	temp = swap->nbrb;
	if (nbr_size(swap->nbrb) > 0)
	{
		swap->nbrb = swap->nbrb->next;
		ft_addnbr_front(&swap->nbra, temp);
	}
	if (swap->print)
		printf("pa\n");
	swap->count_sort++;
}

void	ft_pb(t_swap *swap)
{
	t_nbr	*temp;

	temp = swap->nbra;
	if (nbr_size(swap->nbra) > 0)
	{
		swap->nbra = swap->nbra->next;
		ft_addnbr_front(&swap->nbrb, temp);
	}
	if (swap->print)
		printf("pb\n");
	swap->count_sort++;
}
