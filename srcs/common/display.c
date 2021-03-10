/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:41:45 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 08:41:49 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_rotate(char c, int nb_r, int size_nbr, t_swap *swap)
{
	int i;

	i = -1;
	if (nb_r <= size_nbr / 2)
	{
		while (++i < nb_r)
			if (swap->print)
				printf("r%c\n", c);
		swap->count_sort += i;
	}
	else
	{
		while (++i < size_nbr - nb_r)
			if (swap->print)
				printf("rr%c\n", c);
		swap->count_sort += i;
	}
}

void	display_stack(t_swap *swap)
{
	t_nbr	*nbra;
	t_nbr	*nbrb;

	nbra = swap->nbra;
	nbrb = swap->nbrb;
	if (swap->print)
	{
		while (nbra || nbrb)
		{
			if (nbra)
			{
				printf("\n %d", nbra->nb);
				nbra = nbra->next;
			}
			else
				printf("\n");
			printf("\t");
			if (nbrb)
			{
				printf("%d", nbrb->nb);
				nbrb = nbrb->next;
			}
		}
		printf("\n____________\n a \t b \n\n");
	}
}
