#include "push_swap.h"

static int	is_at_topside(t_stack	*stack, int	max)
{
	int		half;
	int		i;
	t_node	*cur;

	half = stack->count / 2;
	if (stack->count % 2)
		half++;
	i = 0;
	cur = stack->top;
	while (i++ < half)
	{
		if (cur->idx == max)
			return (1);
		cur = cur->next;
	}
	printf("tetet\n");
	return (0);
}

static void	get_max_to_top(t_stacks_ab	*stacks, t_list	**rules, int max)
{
	if (is_at_topside(stacks->stack_b, max))
	{
		while (stacks->stack_b->top->idx != max)
			rb(stacks, rules);
	}
	else
	{
		while (stacks->stack_b->top->idx != max)
			rrb(stacks, rules);
	}
}

void	push_back_to_a(t_stacks_ab	*stacks, t_list	**rules)
{
	int	max;

	if (is_empty(stacks->stack_a))
		max = stacks->stack_b->count;
	else
		max = stacks->stack_a->top->idx - 1;
	while (!is_empty(stacks->stack_b))
	{
		get_max_to_top(stacks, rules, max);
		pa(stacks, rules);
		max = stacks->stack_a->top->idx - 1;
	}
}
