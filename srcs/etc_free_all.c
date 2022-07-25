/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_free_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:06:09 by hyna              #+#    #+#             */
/*   Updated: 2022/07/25 12:11:46 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_stacks(t_stacks_ab *stacks)
{
    int	i;

	i = 0;
	while (!is_empty(stacks->stack_a))
		pop(stacks->stack_a);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}

void    free_all(t_stacks_ab    *stacks, t_list **rules)
{
	free_stacks(stacks);
	ft_lstclear(rules, NULL);
}
