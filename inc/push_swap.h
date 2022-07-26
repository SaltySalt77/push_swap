/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:11:16 by hyna              #+#    #+#             */
/*   Updated: 2022/07/26 19:11:57 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

# define SA "sa"
# define SB "sb"
# define SS "ss"

# define PA "pa"
# define PB "pb"

# define RA "ra"
# define RB "rb"
# define RR "rr"

# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_node {
	int				element;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	struct s_node	*top;
	struct s_node	*bottom;
	int				count;
}	t_stack;

typedef struct s_stacks_ab {
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_stacks_ab;

//stack_utils
t_stack	*init_stack(void);
t_stack	*init_stack_a(int argc, char	**argv);
void	push(int item, t_stack	*stack);
int		is_empty(t_stack	*stack);
int		pop(t_stack	*stack);

//rules
void	archive_used_rule(t_list	**rules, char	*used_rule);
void	print_used_rules(t_list	*rules);
void	pa(t_stacks_ab	*stacks, t_list	**rules);
void	pb(t_stacks_ab	*stacks, t_list	**rules);
void	ra(t_stacks_ab	*stacks, t_list	**rules);
void	rb(t_stacks_ab	*stacks, t_list	**rules);
void	rr(t_stacks_ab	*stacks, t_list	**rules);
void	rra(t_stacks_ab	*stacks, t_list	**rules);
void	rrb(t_stacks_ab	*stacks, t_list	**rules);
void	rrr(t_stacks_ab	*stacks, t_list	**rules);
void	sa(t_stacks_ab	*stacks, t_list	**rules);
void	sb(t_stacks_ab	*stacks, t_list	**rules);
void	ss(t_stacks_ab	*stacks, t_list	**rules);

//algoritm
void	divide_into_chunks(t_stacks_ab	*stacks, t_list	**rules);
void	push_back_to_a(t_stacks_ab	*stacks, t_list	**rules);
int		get_chunk(t_stack	*stack);

//sorting hard code
void	sort_3_elements(t_stacks_ab *stacks, t_list	**rules);
void	sort_4_elements(t_stacks_ab *stacks, t_list	**rules);
void	sort_5_elements(t_stacks_ab *stacks, t_list	**rules);

//error
void	put_error_exit(void);
void	put_everything_in_stack(t_stack	*stack);

//etc
void	free_all(t_stacks_ab	*stacks, t_list	**rules);
void	get_idx(t_stack	*stack);
void	sorting_processor(t_stacks_ab *stacks, t_list	**rules);
int		is_in_asc(t_stack	*stack);
int		is_in_desc(t_stack	*stack);

//checker
void	checker(t_stacks_ab	*stacks, t_list	**rules);

#endif
