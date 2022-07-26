/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:57:04 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 17:45:39 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "libft.h"

static void	r_abr(t_stack	*stack)
{
	int		element;
	int		idx;
	t_node	*bottom;

	idx = stack->top->idx;
	element = pop(stack);
	bottom = malloc(sizeof(*stack));
	if (bottom == NULL)
		put_error_exit();
	stack->bottom->next = bottom;
	bottom->prev = stack->bottom;
	bottom->next = NULL;
	bottom->element = element;
	stack->bottom = bottom;
	stack->bottom->idx = idx;
	stack->count++;
}

void	ra(t_stacks_ab	*stacks, t_list	**rules)
{
	if (stacks->stack_a->count < 2)
		return ;
	r_abr(stacks->stack_a);
	archive_used_rule(rules, RA);
}

void	rb(t_stacks_ab	*stacks, t_list	**rules)
{
	if (stacks->stack_b->count < 2)
		return ;
	r_abr(stacks->stack_b);
	archive_used_rule(rules, RB);
}

void	rr(t_stacks_ab	*stacks, t_list	**rules)
{
	ra(stacks, rules);
	rb(stacks, rules);
}
