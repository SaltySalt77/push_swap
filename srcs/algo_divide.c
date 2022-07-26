/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:06:25 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 22:28:10 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_topside(t_stack	*stack, int num, int chunk)
{
	int		count;
	int		half;
	int		top;
	t_node	*cur;

	count = 0;
	half = stack->count / 2;
	top = stack->top->idx;
	cur = stack->top;
	while (cur != NULL && cur->idx > num + chunk)
	{
		count++;
		if (count > half)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	divide_into_chunks(t_stacks_ab	*stacks, t_list	**rules)
{
	int		chunk;
	int		num;
	t_node	*cur;

	chunk = get_chunk(stacks->stack_a);
	cur = stacks->stack_a->top;
	while (!is_empty(stacks->stack_a))
	{
		num = stacks->stack_b->count;
		if (cur->idx <= num)
			pb(stacks, rules);
		else if (cur->idx > num && cur->idx <= num + chunk)
		{
			pb(stacks, rules);
			rb(stacks, rules);
		}
		else if (cur->idx > num + chunk)
		{
			if (is_topside(stacks->stack_a, num, chunk))
				ra(stacks, rules);
			else
				rra(stacks, rules);
		}
		cur = stacks->stack_a->top;
	}
}
