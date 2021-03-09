#include "../../includes/push_swap.h"

void	ft_ra(t_swap *swap)
{
	t_nbr	*temp;

	if (nbr_size(swap->nbra) > 1)
	{
		temp = swap->nbra;
		swap->nbra = swap->nbra->next;
		temp->next = NULL;
		ft_addnbr_back(&swap->nbra, temp);
	}
	if (swap->print && swap->print_rota)
		printf("ra\n");
	if (swap->print_rota)
		swap->count_sort++;
}

void	ft_rb(t_swap *swap)
{
	t_nbr	*temp;

	if (nbr_size(swap->nbrb) > 1)
	{
		temp = swap->nbrb;
		swap->nbrb = swap->nbrb->next;
		temp->next = NULL;
		ft_addnbr_back(&swap->nbrb, temp);
	}
	if (swap->print && swap->print_rota)
		printf("rb\n");
	if (swap->print_rota)
		swap->count_sort++;
}

void	ft_rr(t_swap *swap)
{
	ft_ra(swap);
	ft_rb(swap);
}
