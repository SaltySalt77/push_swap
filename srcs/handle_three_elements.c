/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_three_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:49:32 by hyna              #+#    #+#             */
/*   Updated: 2022/07/14 17:15:20 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*check_orders(t_stack	*stack_a)
{
	int		i;
	char	*order;
	t_node	*cur;

	i = 0;
	order = malloc(4);
	if (order == NULL)
		put_error_exit();
	cur = stack_a->top;
	while (i < 3)
	{
		order[i] = cur->element;
		cur = cur->next;
		i++;
	}
	return (order);
}

void	sort_3_elements(t_stacks_ab	*stacks, t_list	**rules)
{
	t_stack	*stack_a;
	t_node	*cur;

	stack_a = stacks->stack_a;
	if (is_in_asc(stack_a))
		return ;
	else if (is_in_desc(stack_a))
		sa(stacks, rules);
	cur = stack_a->top;
	if (cur->element < stack_a->bottom->element)
		sa(stacks, rules);
	if (is_in_asc(stack_a))
		return ;
	else if (cur->element > cur->next->element)
		ra(stacks, rules);
	else
		rra(stacks, rules);
}
