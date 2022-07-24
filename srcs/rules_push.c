/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:56:38 by hyna              #+#    #+#             */
/*   Updated: 2022/07/17 20:25:20 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "libft.h"

static void	p_ab(t_stack	*from_stack, t_stack *to_stack)
{
	t_node	*from_node;

	from_node = from_stack->top;
	push(from_node->element, to_stack);
	to_stack->top->idx = from_node->idx;
	if (is_empty(to_stack))
		printf("testing!\n");
	pop(from_stack);
	return ;
}

void	pa(t_stacks_ab	*stacks, t_list	**rules)
{
	if (is_empty(stacks->stack_b))
		return ;
	p_ab(stacks->stack_b, stacks->stack_a);
	printf("%s\n", PA);
	archive_used_rule(rules, PA);
}

void	pb(t_stacks_ab	*stacks, t_list	**rules)
{
	if (is_empty(stacks->stack_a))
		return ;
	p_ab(stacks->stack_a, stacks->stack_b);
	printf("%s\n", PB);
	archive_used_rule(rules, PB);
}
