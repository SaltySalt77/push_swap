/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:05:41 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 17:46:49 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

static void	rr_abr(t_stack *stack)
{
	t_node	*bottom;
	int		idx;

	bottom = stack->bottom;
	idx = bottom->idx;
	push(bottom->element, stack);
	stack->bottom = bottom->prev;
	stack->bottom->next = NULL;
	stack->top->idx = idx;
	stack->count--;
	free(bottom);
}

void	rra(t_stacks_ab	*stacks, t_list	**rules)
{
	if (stacks->stack_a->count < 2)
		return ;
	rr_abr(stacks->stack_a);
	archive_used_rule(rules, RRA);
}

void	rrb(t_stacks_ab	*stacks, t_list	**rules)
{
	if (stacks->stack_b->count < 2)
		return ;
	rr_abr(stacks->stack_b);
	archive_used_rule(rules, RRB);
}

void	rrr(t_stacks_ab	*stacks, t_list	**rules)
{
	rra(stacks, rules);
	rrb(stacks, rules);
}
