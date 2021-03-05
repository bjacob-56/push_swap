/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:58:54 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 08:58:54 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	display_stack(t_swap *swap)
{
	t_nbr	*nbra = swap->nbra;
	t_nbr	*nbrb = swap->nbrb;
	
	while (nbra || nbrb)
	{
		if (nbra)
		{
			printf("\n %d", nbra->nb);
			nbra = nbra->next;
		}
		else
			printf("\n\t");
		printf("\t");
		if (nbrb)
		{
			printf("%d", nbrb->nb);
			nbrb = nbrb->next;
		}
	}
	printf("\n____________\n");
	printf(" a \t b \n\n");
}