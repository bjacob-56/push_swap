#include "../../includes/push_swap.h"

void	ft_exit_failure(t_swap *swap, int error)
{
	(void)error;
	printf("Error\n");
	ft_exit(swap);
}

void	ft_exit(t_swap *swap)
{
	free_all_ptr(swap);
	if (swap->line)
		free(swap->line);
	exit(EXIT_SUCCESS);
}
