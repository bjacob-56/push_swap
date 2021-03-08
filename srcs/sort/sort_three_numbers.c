/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:27:15 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/08 14:27:15 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three_numbers(t_swap *swap)
{
	if (!is_sorted(swap->nbra))
		ft_sa(swap);
	align_to_top_a(swap);
}
