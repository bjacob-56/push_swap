/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:37:16 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 08:37:16 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_swap *swap)
{
	t_nbr*	temp;

	if (nbr_size(swap->nbra) > 1)
	{
		temp = swap->nbra;
		swap->nbra = swap->nbra->next;
		temp->next = NULL;
		ft_addnbr_back(&swap->nbra, temp);
	}
}

void	ft_rb(t_swap *swap)
{
	t_nbr*	temp;

	if (nbr_size(swap->nbrb) > 1)
	{
		temp = swap->nbrb;
		swap->nbrb = swap->nbrb->next;
		temp->next = NULL;
		ft_addnbr_back(&swap->nbrb, temp);
	}
}

void	ft_rr(t_swap *swap)
{
	ft_ra(swap);
	ft_rb(swap);
}