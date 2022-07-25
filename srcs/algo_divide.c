/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:06:25 by hyna              #+#    #+#             */
/*   Updated: 2022/07/25 12:06:34 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide(t_stacks_ab	*stacks, t_list	**rules, int num, int chunk)
{
	t_stack	*stack_b;

	stack_b = stacks->stack_b;
	while (stack_b->count != num + chunk && !is_empty(stacks->stack_a))
	{
		if (stacks->stack_a->top->idx <= num + chunk)
		{
			pb(stacks, rules);
			if (stack_b->top->idx > num)
				rb(stacks, rules);
		}
		else
			ra(stacks, rules);
	}
}

void	divide_into_chunks(t_stacks_ab	*stacks, t_list	**rules)
{
	int	chunk;
	int	num;

	chunk = get_chunk(stacks->stack_a);
	num = chunk;
	while (!is_empty(stacks->stack_a))
	{
		divide(stacks, rules, num, chunk);
		num += chunk * 2;
	}
}
