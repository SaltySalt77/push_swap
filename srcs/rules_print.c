/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:48:54 by hyna              #+#    #+#             */
/*   Updated: 2022/07/17 20:26:10 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"
/*
static char	*is_in_same_time(t_list	*cur)
{
	char	*cur_element;
	char	*next_element;
	int		gap;

	if (cur->next == NULL)
		return (NULL);
	cur_element = cur->content;
	next_element = cur->next->content;
	if (cur_element[0] != next_element[0])
		return (NULL);
	gap = cur_element[1] - next_element[1];
	if (gap == 0 && cur_element[1] == 'r')
		gap = cur_element[2] - cur_element[2];
	if (gap == -1 || gap == 1)
	{
		if (cur_element[0] == 's')
			return (SS);
		else if (cur_element[0] == 'r' && cur_element[1] == 'r')
			return (RRR);
		else if (cur_element[0] == 'r')
			return (RR);
	}
	return (NULL);
}*/

void	print_used_rules(t_list	*rules)
{
	t_list	*cur;
//	char	*rule;

	cur = rules;
	while (cur)
	{
	/*	rule = is_in_same_time(cur);
		if (rule)
		{
			ft_printf("%s\n", rule);
			cur = cur->next;
		}
		else
			ft_printf("%s\n", cur->content);
	*/	ft_printf("%s\n", cur->content);
		cur = cur->next;
	}
}
