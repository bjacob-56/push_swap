#include "../../includes/push_swap.h"

void	apply_instructions(t_swap *swap)
{
	int		i;
	t_inst	*elem;

	while (swap->instruction)
	{
		i = -1;
		while (++i < NB_INSTRUCTIONS)
		{
			if (!ft_strncmp(swap->instruction->inst, swap->default_inst[i],
							ft_strlen(swap->instruction->inst)))
			{
				swap->fct_inst[i](swap);
				elem = swap->instruction;
				swap->instruction = swap->instruction->next;
				i = NB_INSTRUCTIONS;
			}
		}
	}
}
