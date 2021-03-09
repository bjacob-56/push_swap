#include "../../includes/push_swap.h"

t_inst	*ft_instnew(t_swap *swap, char *str)
{
	t_inst	*elem;

	elem = malloc_lst(swap, sizeof(t_inst));
	if (!elem)
		return (NULL);
	ft_memcpy(elem->inst, str, ft_strlen(str) + 1);
	elem->next = NULL;
	return (elem);
}

t_inst	*ft_instlast(t_inst *begin)
{
	if (!begin)
		return (NULL);
	while (begin->next)
		begin = begin->next;
	return (begin);
}

void	ft_addinst_back(t_inst **alst, t_inst *new)
{
	t_inst	*elem;

	if (!(*alst))
		*alst = new;
	else
	{
		elem = ft_instlast(*alst);
		elem->next = new;
	}
}

int		add_inst(t_swap *swap, char *str)
{
	t_inst	*elem;

	elem = ft_instnew(swap, str);
	if (!elem)
		ft_exit_failure(swap, 1);
	ft_addinst_back(&swap->instruction, elem);
	free(swap->line);
	swap->line = NULL;
	return (EXIT_SUCCESS);
}

void	free_inst(t_inst *inst)
{
	t_inst *elem;

	while (inst)
	{
		elem = inst->next;
		free(inst);
		inst = elem;
	}
}
