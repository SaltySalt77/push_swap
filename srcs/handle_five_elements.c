/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_five_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:40:14 by hyna              #+#    #+#             */
/*   Updated: 2022/07/14 17:15:14 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_idx_for_element(t_stacks_ab	*stacks)
{
	int		element;
	int		idx;
	t_node	*cur;

	idx = 1;
	cur = stacks->stack_a->top;
	element = stacks->stack_b->top->element;
	while (cur != NULL)
	{
		if (element < cur->element)
			return (idx);
		idx++;
		cur = cur->next;
	}
	return (idx);
}

static void	sort_with_idx(t_stacks_ab	*stacks, int idx, t_list	**rules)
{
	if (idx <= 2 || idx == stacks->stack_a->count + 1)
	{
		pa(stacks, rules);
		if (idx == 2)
			sa(stacks, rules);
		else if (idx != 1)
			ra(stacks, rules);
	}
	else if (idx == 3)
	{
		ra(stacks, rules);
		pa(stacks, rules);
		sa(stacks, rules);
		rra(stacks, rules);
	}
	else
	{
		rra(stacks, rules);
		pa(stacks, rules);
		ra(stacks, rules);
		ra(stacks, rules);
	}
}

void	sort_4_elements(t_stacks_ab	*stacks, t_list	**rules)
{
	int	idx;

	pb(stacks, rules);
	sort_3_elements(stacks, rules);
	idx = get_idx_for_element(stacks);
	sort_with_idx(stacks, idx, rules);
}

void	sort_5_elements(t_stacks_ab	*stacks, t_list	**rules)
{
	int		idx;

	pb(stacks, rules);
	sort_4_elements(stacks, rules);
	idx = get_idx_for_element(stacks);
	sort_with_idx(stacks, idx, rules);
}
