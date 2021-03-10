/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:44:03 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/10 10:25:24 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	swap;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (init_swap(&swap, &swap, argc, argv) == EXIT_FAILURE)
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
	apply_instructions(&swap);
	final_check(&swap);
	ft_exit(&swap);
	return (EXIT_SUCCESS);
}
