/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_get_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:06:29 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 20:49:53 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk(t_stack	*stack)
{
	int	chunk;
	double	x;
	//double	tmp;

	x = stack->count;
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
	//tmp = chunk - (int) chunk;
	//if (tmp > 0.5)
//		chunk++;
	return (chunk);
}
