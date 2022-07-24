/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:35:32 by hyna              #+#    #+#             */
/*   Updated: 2022/07/17 11:58:00 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sorting_processor(t_stacks_ab	*stacks, t_list	**rules)
{
	if (is_in_asc(stacks->stack_a))
		return ;
	if (stacks->stack_a->count <= 5)
	{
		if (stacks->stack_a->count == 2)
			ra(stacks, rules);
		else if (stacks->stack_a->count == 3)
			sort_3_elements(stacks, rules);
		else if (stacks->stack_a->count == 4)
			sort_4_elements(stacks, rules);
		else if (stacks->stack_a->count == 5)
			sort_5_elements(stacks, rules);
		return ;
	}
	divide_into_chunks(stacks, rules);
	push_back_to_a(stacks, rules);
}
