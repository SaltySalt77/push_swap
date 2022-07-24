/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:18:33 by hyna              #+#    #+#             */
/*   Updated: 2022/07/17 20:25:58 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	put_error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	put_everything_in_stack(t_stack	*stack)
{
	static int	nbr = 1;
	t_node		*cur;

	cur = stack->top;
	while (cur != NULL)
	{
		ft_printf("%d\n", cur->element);
		cur = cur->next;
	}
	ft_printf("testing %d done\n", nbr);
	nbr++;
}

static int	has_duplicats(t_stack	*stack)
{
	t_node	*cur;
	t_node	*compare;

	cur = stack->top;
	while (cur != NULL)
	{
		compare = cur->next;
		while (compare != NULL)
		{
			if (cur->element == compare->element)
				return (1);
			compare = compare->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	t_stacks_ab	*stacks;
	t_list		*rules;

	if (argc < 2)
		put_error_exit();
	stacks = malloc(sizeof(t_stacks_ab));
	if (stacks == NULL)
		put_error_exit();
	stacks->stack_a = init_stack_a(argc, argv);
	if (has_duplicats(stacks->stack_a))
		put_error_exit();
	stacks->stack_b = init_stack();
	if (stacks->stack_b == NULL)
		put_error_exit();
	rules = NULL;
	get_idx(stacks->stack_a);
	sorting_processor(stacks, &rules);
	print_used_rules(rules);
	//put_everything_in_stack(stacks->stack_a);
	exit(0);
}
