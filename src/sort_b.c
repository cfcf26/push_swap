/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:50:34 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/03 06:09:44 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_b_1(t_cdll **stack_b, int len)
{
	int		i;
	t_cdll	*temp;

	i = 0;
	temp = (*stack_b);
	while (temp && (temp->index < len && temp->index >= 0))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

static int	sort_b_2(t_cdll **stack_b, int len)
{
	int		i;
	t_cdll	*temp;

	i = 0;
	temp = (*stack_b);
	while (temp && (temp->index < len && temp->index >= 0))
	{
		i++;
		temp = temp->prev;
	}
	return (i);
}

void	sort_b(t_cdll	**stack_b, int len)
{
	const int	i = sort_b_1(stack_b, len);
	const int	j = sort_b_2(stack_b, len);

	if (i < j)
	{
		while ((*stack_b)->index != len)
			rb(stack_b);
	}
	else
		while ((*stack_b)->index != len)
			rrb(stack_b);
}
