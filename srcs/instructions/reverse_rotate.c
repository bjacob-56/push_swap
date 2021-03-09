#include "../../includes/push_swap.h"

void	ft_rra(t_swap *swap)
{
	t_nbr	*temp;
	t_nbr	*pre_last;

	if (nbr_size(swap->nbra) > 1)
	{
		temp = ft_nbrlast(swap->nbra);
		pre_last = swap->nbra;
		while (pre_last->next->next)
			pre_last = pre_last->next;
		pre_last->next = NULL;
		ft_addnbr_front(&swap->nbra, temp);
	}
	if (swap->print)
		printf("rra\n");
	swap->count_sort++;
}

void	ft_rrb(t_swap *swap)
{
	t_nbr	*temp;
	t_nbr	*pre_last;

	if (nbr_size(swap->nbrb) > 1)
	{
		temp = ft_nbrlast(swap->nbrb);
		pre_last = swap->nbrb;
		while (pre_last->next->next)
			pre_last = pre_last->next;
		pre_last->next = NULL;
		ft_addnbr_front(&swap->nbrb, temp);
	}
	if (swap->print)
		printf("rrb\n");
	swap->count_sort++;
}

void	ft_rrr(t_swap *swap)
{
	ft_rra(swap);
	ft_rrb(swap);
}
