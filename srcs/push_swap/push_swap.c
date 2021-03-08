/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 06:52:09 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 06:52:09 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"



int main(int argc, char **argv)
{	
	t_swap swap;
	t_swap swap1;
	
	if (argc == 1)
		return (EXIT_SUCCESS);
	if (init_swap(&swap, argc, argv) == EXIT_FAILURE)
		exit_failure_checker(&swap, EXIT_FAILURE);
	if (init_swap(&swap1, argc, argv) == EXIT_FAILURE)
		exit_failure_checker(&swap1, EXIT_FAILURE);
	
	sort1(&swap1);
	swap.print = 1;
	sort1(&swap);

	display_stack(&swap);

	free_nbr(swap.nbra);
	free_nbr(swap.nbrb);
	free_nbr(swap1.nbra);
	free_nbr(swap1.nbrb);
	return (EXIT_SUCCESS);
}