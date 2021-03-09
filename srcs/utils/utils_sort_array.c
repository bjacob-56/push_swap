#include "../../includes/push_swap.h"

void	sort_array(int *arr, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int		create_swap_array(t_swap *swap_ptrs, t_swap *swap)
{
	int		i;
	t_nbr	*temp;

	swap->nb_int = nbr_size(swap->nbra);
	swap->arr = malloc_lst(swap_ptrs, swap->nb_int * sizeof(int));
	if (!swap->arr)
		ft_exit_failure(swap, 1);
	i = -1;
	temp = swap->nbra;
	while (++i < swap->nb_int)
	{
		swap->arr[i] = temp->nb;
		temp = temp->next;
	}
	sort_array(swap->arr, swap->nb_int);
	return (EXIT_SUCCESS);
}
