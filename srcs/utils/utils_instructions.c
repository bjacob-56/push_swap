#include "../../includes/push_swap.h"

int	is_instruction(char *str, t_swap *swap)
{
	int i;

	i = -1;
	while (++i < NB_INSTRUCTIONS)
		if (!ft_strncmp(str, swap->default_inst[i],
			ft_strlen(swap->default_inst[i]) + 1))
			return (1);
	return (0);
}
