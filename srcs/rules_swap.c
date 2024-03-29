/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:04:31 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 17:47:32 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

static void	s_abs(t_stack	*stack)
{
	t_node	*top;
	t_node	*next;
	t_node	tmp;

	top = stack->top;
	next = top->next;
	tmp.element = top->element;
	tmp.idx = top->idx;
	top->element = next->element;
	top->idx = next->idx;
	next->element = tmp.element;
	next->idx = tmp.idx;
}

void	sa(t_stacks_ab	*stacks, t_list	**rules)
{
	if (stacks->stack_a->count < 2)
		return ;
	s_abs(stacks->stack_a);
	archive_used_rule(rules, SA);
}

void	sb(t_stacks_ab	*stacks, t_list	**rules)
{
	if (stacks->stack_b->count < 2)
		return ;
	s_abs(stacks->stack_b);
	archive_used_rule(rules, SB);
}

void	ss(t_stacks_ab	*stacks, t_list	**rules)
{
	sa(stacks, rules);
	sb(stacks, rules);
}
