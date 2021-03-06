/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:45:44 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 08:47:27 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_nbr	*ft_nbrnew(t_swap *swap, int nb)
{
	t_nbr	*elem;

	elem = malloc_lst(swap, sizeof(t_nbr));
	if (!elem)
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

int		add_nbr(t_swap *swap_ptrs, t_swap *swap, char *str)
{
	t_nbr	*elem;
	long	nb;

	nb = ft_atoi(str);
	if (nb == (long)INT_MAX + 1)
		ft_exit_failure(swap, 1);
	if (is_in_stack(swap, (int)nb))
		ft_exit_failure(swap, 1);
	elem = ft_nbrnew(swap_ptrs, (int)nb);
	if (!elem)
		ft_exit_failure(swap, 1);
	ft_addnbr_back(&swap->nbra, elem);
	return (EXIT_SUCCESS);
}

void	free_nbr(t_nbr *nbr)
{
	t_nbr *elem;

	while (nbr)
	{
		elem = nbr->next;
		free(nbr);
		nbr = elem;
	}
}
