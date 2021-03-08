/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:21:22 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 10:21:22 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_index_2(t_swap *swap)
{
	swap->tab_index_2[0] = (swap->nb_int - 1) / 2;
	swap->tab_index_2[1] = swap->nb_int - 1;
}

int	get_fist_and_last_int_in_range(t_nbr *temp, int *first, int *last,
										int limit)
{
	int i;
	
	i = 0;
	while (temp)
	{
		if (temp->nb <= limit)
		{
			*last = i;
			if (*first == -1)
				*first = i;
		}
		i++;
		temp = temp->next;
	}
	return (i);
}

void	move_next_int_in_range_to_b(t_swap *swap, int index)
{
	int limit;
	int first_in_range;
	int last_in_range;
	int i;

	limit = swap->arr[swap->tab_index_2[index]];
	first_in_range = -1;
	last_in_range = -1;
	i = get_fist_and_last_int_in_range(swap->nbra, &first_in_range,
										&last_in_range, limit);
	if (first_in_range <= i - last_in_range)
	{
		while (first_in_range-- > 0)
			ft_ra(swap);
	}
	else
	{	
		while (last_in_range++ < i)
			ft_rra(swap);
	}
	insert_topa_in_b(swap);
	swap->count_to_index++;
}

int	sort_medium_numbers(t_swap *swap)
{
	int index;

	if (create_swap_array(swap) == EXIT_FAILURE)
		ft_exit_failure(swap, 1);	 // a gerer
	set_index_2(swap);
	swap->print_rota = 1;
	index = 0;
	swap->count_to_index = 0;
	while (index < 2)
	{
		while (swap->count_to_index <= swap->tab_index_2[index])
			move_next_int_in_range_to_b(swap, index);
		index++;
	}
	align_to_top_b(swap);
	while (swap->nbrb)
		ft_pa(swap);
	return (EXIT_SUCCESS);
}
