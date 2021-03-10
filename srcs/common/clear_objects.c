/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:39:21 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 08:39:22 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*add_lst_to_free(t_swap *swap, void *ptr)
{
	t_list	*elem;

	elem = ft_lstnew(ptr);
	if (!elem)
	{
		free(ptr);
		return (NULL);
	}
	if (!(swap->ptrs))
		swap->ptrs = elem;
	else
		ft_lstadd_back(&swap->ptrs, elem);
	return (ptr);
}

void	*malloc_lst(t_swap *swap, int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (!add_lst_to_free(swap, ptr))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

int		free_all_ptr(t_swap *swap)
{
	ft_lstclear(&swap->ptrs, free);
	return (EXIT_SUCCESS);
}
