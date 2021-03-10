/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:44:16 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 10:10:14 by bjacob           ###   ########lyon.fr   */
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
	while (!a_almost_empty_and_b_sorted(swap))
		insert_topa_in_b(swap);
	if (swap->nbra->nb > swap->nbra->next->nb)
		ft_sa(swap);
	align_to_top_b(swap);
	while (swap->nbrb && swap->nbrb->nb > ft_nbrlast(swap->nbra)->nb)
		ft_pa(swap);
	if (swap->nbra->nb > ft_nbrlast(swap->nbra)->nb)
		ft_rra(swap);
	while (swap->nbrb && swap->nbrb->nb > ft_nbrlast(swap->nbra)->nb)
		ft_pa(swap);
	if (swap->nbra->nb > ft_nbrlast(swap->nbra)->nb)
		ft_rra(swap);
	while (swap->nbrb)
		ft_pa(swap);
}

void	use_best_sort(t_swap *swap)
{
	if (swap->count1 <= swap->count2 && swap->count1 <= swap->count3 &&
		swap->count1 <= swap->count4)
		sort_simple(swap);
	else if (swap->count2 <= swap->count3 && swap->count2 <= swap->count4)
		sort_medium_numbers(swap, swap);
	else if (swap->count3 <= swap->count4)
		sort_high_numbers(swap, swap);
	else
		sort_very_high_numbers(swap, swap);
}

void	init_and_sort_swap(t_swap *swap, int argc, char **argv)
{
	t_swap	swap1;
	t_swap	swap2;
	t_swap	swap3;
	t_swap	swap4;

	if (init_swap(swap, &swap1, argc, argv) == EXIT_FAILURE)
		ft_exit_failure(swap, EXIT_FAILURE);
	if (init_swap(swap, &swap2, argc, argv) == EXIT_FAILURE)
		ft_exit_failure(swap, EXIT_FAILURE);
	if (init_swap(swap, &swap3, argc, argv) == EXIT_FAILURE)
		ft_exit_failure(swap, EXIT_FAILURE);
	if (init_swap(swap, &swap4, argc, argv) == EXIT_FAILURE)
		ft_exit_failure(swap, EXIT_FAILURE);
	sort_simple(&swap1);
	sort_medium_numbers(swap, &swap2);
	sort_high_numbers(swap, &swap3);
	if (swap->nb_int > 20)
		sort_very_high_numbers(swap, &swap4);
	else
		swap4.count_sort = swap1.count_sort + 1;
	swap->count1 = swap1.count_sort;
	swap->count2 = swap2.count_sort;
	swap->count3 = swap3.count_sort;
	swap->count4 = swap4.count_sort;
}

int		main(int argc, char **argv)
{
	t_swap	swap;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (init_swap(&swap, &swap, argc, argv) == EXIT_FAILURE)
		ft_exit_failure(&swap, EXIT_FAILURE);
	swap.print = 1;
	swap.nb_int = nbr_size(swap.nbra);
	if (swap.nb_int <= 3)
		sort_few_numbers(&swap);
	else if (!is_sorted(swap.nbra) || swap.nbra->nb != nbr_min(swap.nbra))
	{
		init_and_sort_swap(&swap, argc, argv);
		use_best_sort(&swap);
	}
	ft_exit(&swap);
	return (EXIT_SUCCESS);
}
