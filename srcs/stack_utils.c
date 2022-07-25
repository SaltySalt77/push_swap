/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:18:25 by hyna              #+#    #+#             */
/*   Updated: 2022/07/25 22:01:11 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		put_error_exit();
	stack->top = NULL;
	stack->bottom = NULL;
	stack->count = 0;
	return (stack);
}

void	push(int item, t_stack	*stack)
{
	t_node	*new_element;
	t_node	*sec_element;

	new_element = malloc(sizeof(t_stack));
	if (new_element == NULL)
		put_error_exit();
	new_element->element = item;
	new_element->next = stack->top;
	new_element->prev = NULL;
	if (stack->top != NULL)
	{
		sec_element = stack->top;
		sec_element->prev = new_element;
	}
	stack->top = new_element;
	if (stack->bottom == NULL)
		stack->bottom = stack->top;
	stack->count++;
}

int	pop(t_stack	*stack)
{
	t_node	*pop;
	t_node	*top;
	int		element;

	pop = stack->top;
	top = stack->top->next;
	if (top)
		top->prev = NULL;
	stack->top = top;
	stack->count--;
	element = pop->element;
	free(pop);
	return (element);
}

int	is_empty(t_stack	*stack)
{
	if (stack->count)
		return (0);
	return (1);
}
