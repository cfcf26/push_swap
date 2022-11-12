/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:03:36 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/09 21:16:08 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_a_next(t_cdll **stack_a, int chunk)
{
	t_cdll	*temp;
	int		i;

	i = 0;
	temp = (*stack_a)->next;
	while ((*stack_a) != temp)
	{
		if (temp->index < chunk)
			return (i);
		i++;
		temp = temp->next;
	}
	return (i);
}

static int	sort_a_prev(t_cdll **stack_a, int chunk)
{
	t_cdll	*temp;
	int		i;

	i = 0;
	temp = (*stack_a)->prev;
	while ((*stack_a) != temp)
	{
		if (temp->index < chunk)
			return (i);
		i++;
		temp = temp->prev;
	}
	return (i);
}

static int	sort_a(t_cdll **stack_a, int chunk)
{
	const int	i = sort_a_next(stack_a, chunk);
	const int	j = sort_a_prev(stack_a, chunk);

	if (i <= j)
		return (1);
	else
		return (0);
}

static void	sort_2(t_cdll **stack_a, t_cdll **stack_b, int len)
{
	while (len > 0)
	{
		sort_b(stack_b, len);
		pa(stack_a, stack_b);
		len--;
	}
}

void	sort(t_cdll **stack_a, t_cdll **stack_b, int chunk, int len)
{
	int			i;

	i = 0;
	while ((*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_b, stack_a);
			i++;
		}
		else if ((*stack_a)->index > i && (*stack_a)->index <= i + chunk)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index > (i + chunk))
		{
			if (sort_a(stack_a, chunk))
				ra(stack_a);
			else
				rra(stack_a);
		}
	}
	sort_2(stack_a, stack_b, len);
}
