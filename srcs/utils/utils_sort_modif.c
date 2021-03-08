/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_modif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:11:07 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/08 15:11:07 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	align_to_top_a(t_swap *swap)
{
	int mina;
	int count;

	mina = nbr_min(swap->nbra);
	count = 0;
	while (swap->nbra->nb != mina)
	{
		ft_ra(swap);
		count++;
	}
	print_rotate('a', count, nbr_size(swap->nbra), swap);
}


void	align_to_top_b(t_swap *swap)
{
	int maxb;
	int count;

	maxb = nbr_max(swap->nbrb);
	count = 0;
	swap->print_rota = 0;
	while (swap->nbrb->nb != maxb)
	{
		ft_rb(swap);
		count++;
	}
	swap->print_rota = 1;
	print_rotate('b', count, nbr_size(swap->nbrb), swap);
}

void	insert_topa_in_b(t_swap *swap)
{
	int i;
	int	nba;
	int	maxb;
	int	minb;

	nba = swap->nbra->nb;
	i = 0;
	swap->print_rota = 0;
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
	swap->print_rota = 1;
	ft_pb(swap);
}
