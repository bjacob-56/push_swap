/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:46:02 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/05 07:46:02 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exit_failure_checker(t_swap *swap, int error)
{
	(void)error;
	printf("Error\n");
	exit_checker(swap);
}

void	exit_checker(t_swap *swap)
{
	free_nbr(swap->nbra);
	free_nbr(swap->nbrb);
	free_inst(swap->instruction);
	if (swap->line)
		free(swap->line);
	exit(EXIT_SUCCESS);
}
