/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_get_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:06:29 by hyna              #+#    #+#             */
/*   Updated: 2022/07/25 12:06:36 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk(t_stack	*stack)
{
	int	chunk;

	chunk = 15;
	if (stack->count < 100)
		chunk *= 1;
	else if (stack->count < 500)
		chunk *= 2;
	else if (stack->count < 1000)
		chunk *= 3;
	else if (stack->count < 2000)
		chunk *= 5;
	else
		chunk *= 10;
	return (chunk);
}
