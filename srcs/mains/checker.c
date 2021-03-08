/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 06:52:09 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 06:52:09 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"



int main(int argc, char **argv)
{	
	t_swap swap;
	
	if (argc == 1)
		return (EXIT_SUCCESS);
	if (init_swap(&swap, argc, argv) == EXIT_FAILURE)
		ft_exit_failure(&swap, EXIT_FAILURE);
	
	while (get_next_line(0, &swap.line))
	{	
		if (is_instruction(swap.line, &swap))
		{
			if (add_inst(&swap, swap.line) == EXIT_FAILURE)
				ft_exit_failure(&swap, EXIT_FAILURE);
		}
		else
			ft_exit_failure(&swap, EXIT_FAILURE);
	}

	display_stack(&swap);
	apply_instructions(&swap);
	display_stack(&swap);

	final_check(&swap);

	swap.print = 1;

	display_stack(&swap); // display

	ft_exit(&swap);
	return (EXIT_SUCCESS);
}