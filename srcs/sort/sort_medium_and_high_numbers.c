#include "../../includes/push_swap.h"

void	set_index(t_swap *swap)
{
	swap->tab_index_2[0] = (swap->nb_int / 2) - 1;
	swap->tab_index_2[1] = swap->nb_int - 1;
	if (swap->nb_int < 5)
		swap->tab_index_5[0] = 0;
	else
		swap->tab_index_5[0] = (swap->nb_int / 5) - 1;
	swap->tab_index_5[1] = (swap->nb_int * 2 / 5) - 1;
	swap->tab_index_5[2] = (swap->nb_int * 3 / 5) - 1;
	swap->tab_index_5[3] = (swap->nb_int * 4 / 5) - 1;
	swap->tab_index_5[4] = swap->nb_int - 1;
}

int		get_first_and_last_int_in_range(t_nbr *temp, int *first, int *last,
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

void	move_next_int_in_range_to_b(t_swap *swap, int limit)
{
	int first_in_range;
	int last_in_range;
	int i;

	first_in_range = -1;
	last_in_range = -1;
	i = get_first_and_last_int_in_range(swap->nbra, &first_in_range,
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

int		sort_medium_numbers(t_swap *swap_ptrs, t_swap *swap)
{
	int index;
	int limit;

	if (create_swap_array(swap_ptrs, swap) == EXIT_FAILURE)
		ft_exit_failure(swap, 1);
	swap->nb_int = nbr_size(swap->nbra);
	set_index(swap);
	swap->print_rota = 1;
	index = 0;
	swap->count_to_index = 0;
	while (index < 2)
	{
		limit = swap->arr[swap->tab_index_2[index]];
		while (swap->count_to_index <= swap->tab_index_2[index])
			move_next_int_in_range_to_b(swap, limit);
		index++;
	}
	align_to_top_b(swap);
	while (swap->nbrb)
		ft_pa(swap);
	return (EXIT_SUCCESS);
}

int		sort_high_numbers(t_swap *swap_ptrs, t_swap *swap)
{
	int index;
	int	limit;

	if (create_swap_array(swap_ptrs, swap) == EXIT_FAILURE)
		ft_exit_failure(swap, 1);
	swap->nb_int = nbr_size(swap->nbra);
	set_index(swap);
	swap->print_rota = 1;
	index = 0;
	swap->count_to_index = 0;
	while (index < 5)
	{
		limit = swap->arr[swap->tab_index_5[index]];
		while (swap->count_to_index <= swap->tab_index_5[index])
			move_next_int_in_range_to_b(swap, limit);
		index++;
	}
	align_to_top_b(swap);
	while (swap->nbrb)
		ft_pa(swap);
	return (EXIT_SUCCESS);
}
