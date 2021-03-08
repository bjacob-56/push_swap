/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nbr2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:19:19 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 08:19:19 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	nbr_size(t_nbr *nbr)
{
	int size;

	size = 0;
	while (nbr)
	{
		nbr = nbr->next;
		size++;
	}
	return (size);
}

int	nbr_min(t_nbr *nbr)
{
	int min;

	min = nbr->nb;
	while (nbr)
	{
		if (nbr->nb < min)
			min = nbr->nb;
		nbr = nbr->next;
	}
	return (min);
}

int	nbr_max(t_nbr *nbr)
{
	int max;

	max = nbr->nb;
	while (nbr)
	{
		if (nbr->nb > max)
			max = nbr->nb;
		nbr = nbr->next;
	}
	return (max);
}

t_nbr	*ft_nbrlast(t_nbr *begin)
{
	if (!begin)
		return (NULL);
	while (begin->next)
		begin = begin->next;
	return (begin);
}

int	is_in_stack(t_swap *swap, int nb)
{
	t_nbr	*nbr;

	nbr = swap->nbra;
	while (nbr)
	{
		if (nb == nbr->nb)
			return (1);
		nbr = nbr->next;
	}
	return (0);
}