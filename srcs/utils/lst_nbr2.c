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