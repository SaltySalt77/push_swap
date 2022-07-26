/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:16:59 by hyna              #+#    #+#             */
/*   Updated: 2022/07/25 14:56:31 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	is_all_digit(char	*str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	is_in_int_range(int nbr, char	*element)
{
	char	*compare;

	compare = ft_itoa(nbr);
	if (compare == NULL || ft_strncmp(element, compare, ft_strlen(element)))
	{
		if (element[0] != '+' && element[0] != '0')
			put_error_exit();
	}
	free(compare);
	return (1);
}	

static void	push_multiple(char	*str, t_stack	*stack)
{
	char	**elements;
	int		i;
	int		nbr;

	i = 0;
	elements = ft_split(str, ' ');
	if (elements == NULL)
		put_error_exit();
	while (elements[i])
		i++;
	while (--i >= 0)
	{
		if (is_all_digit(elements[i]))
		{
			nbr = ft_atoi(elements[i]);
			if (is_in_int_range(nbr, elements[i]))
				push(ft_atoi(elements[i]), stack);
		}
		else
			put_error_exit();
	}
	i = 0;
	while (elements[i])
		free(elements[i++]);
	free(elements);
}

t_stack	*init_stack_a(int argc, char	**argv)
{
	t_stack	*stack_a;
	int		nbr;

	stack_a = init_stack();
	while (--argc > 0)
	{
		if (is_all_digit(argv[argc]))
		{
			nbr = ft_atoi(argv[argc]);
			if (is_in_int_range(nbr, argv[argc]))
				push(ft_atoi(argv[argc]), stack_a);
		}
		else
			push_multiple(argv[argc], stack_a);
	}
	return (stack_a);
}
