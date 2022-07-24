/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:45:11 by hyna              #+#    #+#             */
/*   Updated: 2022/07/17 20:25:27 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	archive_used_rule(t_list	**rules, char	*used_rule)
{
	t_list	*new;

	new = ft_lstnew(used_rule);
	if (new == NULL)
		put_error_exit();
	ft_lstadd_back(rules, new);
}
