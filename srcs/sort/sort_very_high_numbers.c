/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_very_high_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:45:03 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 10:07:54 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_index_high(t_swap *swap)
{
	int i;

	i = -1;
	while (++i < HIGH_NB)
		swap->tab_index_high[i] = (swap->nb_int * (i + 1) / HIGH_NB) - 1;
}

int		sort_very_high_numbers(t_swap *swap_ptrs, t_swap *swap)
{
	int index;
	int	limit;

	if (create_swap_array(swap_ptrs, swap) == EXIT_FAILURE)
		ft_exit_failure(swap, 1);
	swap->nb_int = nbr_size(swap->nbra);
	set_index_high(swap);
	swap->print_rota = 1;
	index = 0;
	swap->count_to_index = 0;
	while (index < HIGH_NB)
	{
		limit = swap->arr[swap->tab_index_high[index]];
		while (swap->count_to_index <= swap->tab_index_high[index])
			move_next_int_in_range_to_b(swap, limit);
		index++;
	}
	align_to_top_b(swap);
	while (swap->nbrb)
		ft_pa(swap);
	return (EXIT_SUCCESS);
}
