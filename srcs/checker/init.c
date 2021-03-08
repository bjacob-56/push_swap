/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:13:58 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 12:13:58 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	fill_default_inst(t_swap *swap)
{
	ft_memcpy(swap->default_inst[0], "sa", ft_strlen("sa") + 1);
	ft_memcpy(swap->default_inst[1], "sb", ft_strlen("sb") + 1);
	ft_memcpy(swap->default_inst[2], "ss", ft_strlen("ss") + 1);
	ft_memcpy(swap->default_inst[3], "pa", ft_strlen("pa") + 1);
	ft_memcpy(swap->default_inst[4], "pb", ft_strlen("pb") + 1);
	ft_memcpy(swap->default_inst[5], "ra", ft_strlen("ra") + 1);
	ft_memcpy(swap->default_inst[6], "rb", ft_strlen("rb") + 1);
	ft_memcpy(swap->default_inst[7], "rr", ft_strlen("rr") + 1);
	ft_memcpy(swap->default_inst[8], "rra", ft_strlen("rra") + 1);
	ft_memcpy(swap->default_inst[9], "rrb", ft_strlen("rrb") + 1);
	ft_memcpy(swap->default_inst[10], "rrr", ft_strlen("rrr") + 1);
}

void	fill_fct_inst(t_swap *swap)
{
	swap->fct_inst[0] = &ft_sa;
	swap->fct_inst[1] = &ft_sb;
	swap->fct_inst[2] = &ft_ss;
	swap->fct_inst[3] = &ft_pa;
	swap->fct_inst[4] = &ft_pb;
	swap->fct_inst[5] = &ft_ra;
	swap->fct_inst[6] = &ft_rb;
	swap->fct_inst[7] = &ft_rr;
	swap->fct_inst[8] = &ft_rra;
	swap->fct_inst[9] = &ft_rrb;
	swap->fct_inst[10] = &ft_rrr;
}

int	get_nbr_in_stack(t_swap *swap, int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_is_word_fulldigit(argv[i]))
		{
			if (add_nbr(swap, argv[i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_swap(t_swap *swap, int argc, char **argv)
{
	swap->nbra = NULL;
	swap->nbrb = NULL;
	swap->instruction = NULL;
	swap->line = NULL;
	swap->print = 0;
	swap->count_sort = 0;
	fill_default_inst(swap);
	fill_fct_inst(swap);
	return (get_nbr_in_stack(swap, argc, argv));
}
