/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:43:18 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/09 18:59:22 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_cdll **stack, int size)
{
	const t_cdll	*temp_1 = (*stack);
	const t_cdll	*temp_2 = (*stack)->next->next;

	if (temp_1->index == size - 2 && temp_2->index == size - 1)
	{
		rra(stack);
		sa(stack);
	}
	else if (temp_1->index == size && temp_2->index == size - 2)
	{
		sa(stack);
		rra(stack);
	}
	else if (temp_1->index == size && temp_2->index == size - 1)
		ra(stack);
	else if (temp_1->index == size - 1 && temp_2->index == size - 2)
		rra(stack);
	else if (temp_1->index == size - 1 && temp_2->index == size)
		sa(stack);
}

static void	sort_5_b(t_cdll **stack_a, t_cdll **stack_b)
{
	if ((*stack_b)->index == 1)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_4(t_cdll **stack_a, t_cdll	**stack_b)
{
	int		i;

	i = 4;
	while (i > 0)
	{
		if ((*stack_a)->index == 1)
		{
			pb(stack_b, stack_a);
			break ;
		}
		ra(stack_a);
	}
	sort_3(stack_a, 4);
	pa(stack_a, stack_b);
}

void	sort_5(t_cdll **stack_a, t_cdll	**stack_b)
{
	int		cunt;
	int		i;

	cunt = 0;
	i = 5;
	while (i > 0)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
		{
			pb(stack_b, stack_a);
			cunt++;
		}
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
		{
			pb(stack_b, stack_a);
			cunt++;
		}
		if (cunt >= 2)
			break ;
		ra(stack_a);
	}
	sort_3(stack_a, 5);
	sort_5_b(stack_a, stack_b);
}
