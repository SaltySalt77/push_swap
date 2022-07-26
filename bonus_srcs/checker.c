/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:09 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 17:05:40 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include "ft_printf.h"

char	**get_instr(void)
{
	char	**instr;
	char	*prevs;
	char	*cur;

	while (1)
	{
		cur = get_next_line(0);
		if (cur	== NULL || cur[0] < 0)
			break ;
		if (cur != NULL)
		{
			prevs = ft_strjoin_free(prevs, cur);
			if (prevs == NULL)
				put_error_exit();
		}
	}
	instr = ft_split(prevs, '\n');
	free(prevs);
	return (instr);
}

static void	excute_push_swap(t_stacks_ab	*stacks, char	*instr)
{
	if (ft_strncmp(instr, SA, 3) == 0 || ft_strncmp(instr, SS, 3) == 0)
		sa(stacks, NULL);
	if (ft_strncmp(instr, SB, 3) == 0 || ft_strncmp(instr, SS, 3) == 0)
		sb(stacks, NULL);
	if (ft_strncmp(instr, PA, 3) == 0)
		pa(stacks, NULL);
	else if (ft_strncmp(instr, PB, 3) == 0)
		pb(stacks, NULL);
}

static void	excute_rotates(t_stacks_ab	*stacks, char	*instr)
{
	if (ft_strncmp(instr, RA, 3) == 0 || ft_strncmp(instr, RR, 3) == 0)
		ra(stacks, NULL);
	else if (ft_strncmp(instr, RRA, 3) == 0 || ft_strncmp(instr, RRR, 3) == 0)
		rra(stacks, NULL);
	if (ft_strncmp(instr, RB, 3) == 0 || ft_strncmp(instr, RR, 3) == 0)
		rb(stacks, NULL);
	else if (ft_strncmp(instr, RRB, 3) == 0 || ft_strncmp(instr, RRR, 3) == 0)
		rrb(stacks, NULL);
}

static void	check_and_excute(t_stacks_ab	*stacks, char	*instr)
{
	if (instr[0] == 'r')
		excute_rotates(stacks, instr);
	else if (instr[0] == 's' || instr[0] == 'p')
		excute_push_swap(stacks, instr);
	else if (instr[0] < 32 || instr[0] > 126)
		return ;
	else
		put_error_exit();
}

void	put_stacks(t_stack	*stack)
{
	t_node *cur;

	cur = stack->top;
	while (cur != NULL)
	{
		ft_printf("%d\n", cur->element);
		cur = cur->next;
	}
	ft_printf("-------\n");
}

void	checker(t_stacks_ab	*stacks)
{
	char	**instr;
	int		i;

	i = 0;
	instr = get_instr();
	put_stacks(stacks->stack_a);
	while (instr[i] != NULL)
		check_and_excute(stacks, instr[i++]);
	while (i >= 0)
		free(instr[i--]);
	free(instr);
	put_stacks(stacks->stack_a);
	put_stacks(stacks->stack_b);
	if (is_in_asc(stacks->stack_a) && is_empty(stacks->stack_b))
		ft_putstr_fd("OK\n", 2);
	else
		ft_printf("KO\n");
}
