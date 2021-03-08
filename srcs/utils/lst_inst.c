/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:32:49 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 07:32:49 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

t_inst	*ft_instnew(char *str)
{
	t_inst	*elem;

	if (!(elem = malloc(sizeof(t_inst))))
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

int	add_inst(t_swap *swap, char *str)
{
	t_inst	*elem;
	
	elem = ft_instnew(str);
	if (!elem)
		return (EXIT_FAILURE);
	ft_addinst_back(&swap->instruction, elem);
	free(swap->line);
	return (EXIT_SUCCESS);
}

void	free_inst(t_inst* inst)
{
	t_inst *elem;
	
	while (inst)
	{
		elem = inst->next;
		free(inst);
		inst = elem;
	}
}
