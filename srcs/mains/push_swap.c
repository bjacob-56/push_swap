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

void	sort_few_numbers(t_swap *swap)
{
	if (nbr_size(swap->nbra) >= 2 && !is_sorted(swap->nbra))
		ft_sa(swap);
	align_to_top_a(swap);
}

void	sort1(t_swap *swap)
{
	while (!a_empty_and_b_sorted(swap))
		insert_topa_in_b(swap);
	align_to_top_b(swap);
	while (swap->nbrb)
		ft_pa(swap);
}

int main(int argc, char **argv)
{	
	t_swap swap;
	t_swap swap1;
	
	if (argc == 1)
		return (EXIT_SUCCESS);
	if (init_swap(&swap, argc, argv) == EXIT_FAILURE)
		ft_exit_failure(&swap, EXIT_FAILURE);
	swap.print = 1;
	if (nbr_size(swap.nbra) <= 3)
		sort_few_numbers(&swap);
	else
	{
		if (init_swap(&swap1, argc, argv) == EXIT_FAILURE) // a gerer mieux
			ft_exit_failure(&swap1, EXIT_FAILURE);
		sort1(&swap1);
		sort_medium_numbers(&swap);	// valeur retour a checker
	}
	// display_stack(&swap);
	ft_exit(&swap);
	return (EXIT_SUCCESS);
}