/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push_back_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:06:41 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 20:52:33 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_at_topside(t_stack	*stack, int max)
{
	int		half;
	int		i;
	t_node	*cur;

	half = stack->count / 2;
	i = 0;
	cur = stack->top;
	while (i++ < half)
	{
		if (cur->idx == max)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static void	get_max_to_top(t_stacks_ab	*stacks, t_list	**rules, int max)
{
	if (is_at_topside(stacks->stack_b, max))
	{
		while (stacks->stack_b->top->idx != max)
		{
			// if (stacks->stack_b->top->next->idx == max)
			// 	sb(stacks, rules);
			// else
			rb(stacks, rules);
		}
	}
	else
	{
		while (stacks->stack_b->top->idx != max)
			rrb(stacks, rules);
	}
}

void	push_back_to_a(t_stacks_ab	*stacks, t_list	**rules)
{
	int	max;

	if (is_empty(stacks->stack_a))
		max = stacks->stack_b->count;
	else
		max = stacks->stack_a->top->idx - 1;
	while (!is_empty(stacks->stack_b))
	{
		get_max_to_top(stacks, rules, max);
		pa(stacks, rules);
		max = stacks->stack_a->top->idx - 1;
	}
}
