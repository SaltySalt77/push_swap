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
