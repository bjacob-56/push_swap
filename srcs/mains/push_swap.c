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

void	sort_simple(t_swap *swap)
{
	while (!a_empty_and_b_sorted(swap))
		insert_topa_in_b(swap);
	align_to_top_b(swap);
	while (swap->nbrb)
		ft_pa(swap);
}

void	use_best_sort(t_swap *swap, int count1, int count2, int count3)
{
	if (count1 <= count2 && count1 <= count3)
		sort_simple(swap);
	else if (count2 <= count3)
		sort_medium_numbers(swap);
	else
		sort_high_numbers(swap);
}

int main(int argc, char **argv)
{	
	t_swap swap;
	t_swap swap1;
	t_swap swap2;
	t_swap swap3;
	
	if (argc == 1)
		return (EXIT_SUCCESS);
	if (init_swap(&swap, argc, argv) == EXIT_FAILURE)
		ft_exit_failure(&swap, EXIT_FAILURE);
	swap.print = 1;
	swap.nb_int = nbr_size(swap.nbra);
	if (swap.nb_int <= 3)
		sort_few_numbers(&swap);
	else
	{
		if (init_swap(&swap1, argc, argv) == EXIT_FAILURE)
			ft_exit_failure(&swap, EXIT_FAILURE);
		if (init_swap(&swap2, argc, argv) == EXIT_FAILURE) // a gerer mieux
			ft_exit_failure(&swap, EXIT_FAILURE);
		if (init_swap(&swap3, argc, argv) == EXIT_FAILURE) // a gerer mieux
			ft_exit_failure(&swap, EXIT_FAILURE);
		sort_simple(&swap1);
		sort_medium_numbers(&swap2);
		sort_high_numbers(&swap3);

		printf("count swap1 = %d\n", swap1.count_sort);
		printf("count swap2 = %d\n", swap2.count_sort);
		printf("count swap3 = %d\n", swap3.count_sort);

		use_best_sort(&swap, swap1.count_sort, swap2.count_sort, swap3.count_sort);
	}

	// display_stack(&swap);
	ft_exit(&swap);
	return (EXIT_SUCCESS);
}