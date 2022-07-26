/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:09 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 18:19:17 by hyna             ###   ########.fr       */
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
	int		i;

	i = 0;
	prevs = ft_strdup("\n");
	if (prevs == NULL)
		put_error_exit();
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

static void	excute_instr(t_stacks_ab	*stacks, char	*instr)
{
	if (ft_strncmp(instr, SA, 3) == 0)
		sa(stacks, NULL);
	else if (ft_strncmp(instr, SB, 3) == 0)
		sb(stacks, NULL);
	else if (ft_strncmp(instr, SS, 3) == 0)
		ss(stacks, NULL);
	else if (ft_strncmp(instr, PA, 3) == 0)
		pa(stacks, NULL);
	else if (ft_strncmp(instr, PB, 3) == 0)
		pb(stacks, NULL);
	else if (ft_strncmp(instr, RA, 3) == 0)
		ra(stacks, NULL);
	else if (ft_strncmp(instr, RB, 3) == 0)
		rb(stacks, NULL);
	else if (ft_strncmp(instr, RR, 3) == 0 && ft_strlen(instr) == 2)
		rr(stacks, NULL);
	else if (ft_strncmp(instr, RRA, 4) == 0)
		rra(stacks, NULL);
	else if (ft_strncmp(instr, RRB, 4) == 0)
		rrb(stacks, NULL);
	else if (ft_strncmp(instr, RRR, 4) == 0)
		rrr(stacks, NULL);
	else
		put_error_exit();
}

void	checker(t_stacks_ab	*stacks)
{
	char	**instr;
	int		i;

	i = 0;
	instr = get_instr();
	while (instr[i] != NULL)
	{
		if (instr[i][0] < 32 || instr[i][0] > 126)
			break ;
		excute_instr(stacks, ft_strtrim(instr[i], " "));
		free(instr[i++]);
	}
	free(instr);
	if (is_in_asc(stacks->stack_a) && is_empty(stacks->stack_b))
		ft_putstr_fd("OK\n", 2);
	else
		ft_printf("KO\n");
}
