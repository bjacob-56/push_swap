/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:08:22 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 07:08:22 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_nbr	*ft_nbrnew(int nb)
{
	t_nbr	*elem;

	if (!(elem = malloc(sizeof(t_nbr))))
		return (NULL);
	elem->nb = nb;
	elem->next = NULL;
	return (elem);
}

void	ft_addnbr_back(t_nbr **alst, t_nbr *new)
{
	t_nbr	*elem;

	if (!(*alst))
	{
		new->next = NULL;
		*alst = new;
	}
	else
	{
		elem = ft_nbrlast(*alst);
		elem->next = new;
	}
}

void	ft_addnbr_front(t_nbr **alst, t_nbr *new)
{
	if (!(*alst))
	{
		new->next = NULL;
		*alst = new;
	}
	else
	{
		new->next = *alst;
		*alst = new;
	}
}

int	add_nbr(t_swap *swap, char *str)
{
	t_nbr	*elem;
	long	nb;
	
	nb = ft_atoi(str);
	if (nb == (long)INT_MAX + 1)
		return (EXIT_FAILURE);
	if (is_in_stack(swap, (int)nb))
		return (EXIT_FAILURE);
	elem = ft_nbrnew((int)nb);
	if (!elem)
		return (EXIT_FAILURE);
	ft_addnbr_back(&swap->nbra, elem);
	return (EXIT_SUCCESS);
}

void	free_nbr(t_nbr* nbr)
{
	t_nbr *elem;
	
	while (nbr)
	{
		elem = nbr->next;
		free(nbr);
		nbr = elem;
	}
}