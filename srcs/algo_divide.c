/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:06:25 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 19:22:27 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_rra(t_stacks_ab	*stacks, t_list	**rules, int num, int chunk)
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
			rra(stacks, rules);
	}
}

static void	divide_ra(t_stacks_ab	*stacks, t_list	**rules, int num, int chunk)
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

static int	is_topside(t_stack	*stack)
{
	int		count;
	int		half;
	int		top;
	t_node	*cur;

	count = 0;
	half = stack->count / 2;
	top = stack->top->idx;
	cur = stack->top;
	while (cur != NULL)
	{
		if (cur->idx < top)
			count++;
		if (count > half)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	divide_into_chunks(t_stacks_ab	*stacks, t_list	**rules)
{
	int	chunk;
	int	num;
	int	flag;

	chunk = get_chunk(stacks->stack_a);
	num = chunk;
	flag = is_topside(stacks->stack_a);
	while (!is_empty(stacks->stack_a))
	{
		if (flag)
			divide_ra(stacks, rules, num, chunk);
		else
			divide_rra(stacks, rules, num, chunk);
		num += chunk * 2;
	}
}
