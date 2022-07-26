/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:35:55 by hyna              #+#    #+#             */
/*   Updated: 2022/07/01 20:09:23 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_asc(t_stack	*stack)
{
	t_node	*cur;
	t_node	*compare;

	cur = stack->top;
	while (cur != NULL)
	{
		compare = cur->next;
		while (compare != NULL)
		{
			if (cur->element > compare->element)
				return (0);
			compare = compare->next;
		}
		cur = cur->next;
	}
	return (1);
}

int	is_in_desc(t_stack	*stack)
{
	t_node	*cur;
	t_node	*compare;

	cur = stack->bottom;
	while (cur != NULL)
	{
		compare = cur->prev;
		while (compare != NULL)
		{
			if (cur->element > compare->element)
				return (0);
			compare = compare->prev;
		}
		cur = cur->prev;
	}
	return (1);
}
