/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:06:54 by hyna              #+#    #+#             */
/*   Updated: 2022/07/25 12:07:48 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_min_max(t_stack	*stack, t_node	**min, t_node	**max)
{
	t_node	*cur;

	cur = stack->top;
	while (cur != NULL)
	{
		if ((*min)->element > cur->element)
			(*min) = cur;
		else if ((*max)->element < cur->element)
			(*max) = cur;
		cur = cur->next;
	}
	(*min)->idx = 1;
	(*max)->idx = stack->count;
}

static void	get_sec_min_max(t_stack	*stack, t_node	**min, t_node	**max)
{
	t_node	*cur;
	t_node	*sec_min;
	t_node	*sec_max;

	cur = stack->top;
	sec_min = *max;
	sec_max = *min;
	while (cur != NULL)
	{
		if (cur->element > (*min)->element && cur->element < sec_min->element)
			sec_min = cur;
		if (cur->element < (*max)->element && cur->element > sec_max->element)
			sec_max = cur;
		cur = cur->next;
	}
	sec_min->idx = (*min)->idx + 1;
	if ((*min)->idx + 1 != (*max)->idx - 1)
		sec_max->idx = (*max)->idx - 1;
	*min = sec_min;
	*max = sec_max;
}

void	get_idx(t_stack	*stack)
{
	t_node	*min;
	t_node	*max;
	int		time;
	int		i;

	min = stack->top;
	max = min;
	get_min_max(stack, &min, &max);
	time = stack->count / 2;
	if (stack->count % 2 == 1)
		time++;
	i = 0;
	while (i++ < time)
		get_sec_min_max(stack, &min, &max);
}
