/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:03:36 by ekwak             #+#    #+#             */
/*   Updated: 2022/10/31 00:00:23 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	rra(t_cdll **stack_a)
{
	if ((*stack_a) == NULL)
		err();
	(*stack_a) = (*stack_a)->prev;
	ft_print_s("rra\n");
}

void	rrb(t_cdll **stack_b)
{
	if ((*stack_b) == NULL)
		err();
	(*stack_b) = (*stack_b)->prev;
	ft_print_s("rrb\n");
}

void	rrr(t_cdll **stack_a, t_cdll **stack_b)
{
	if (((*stack_a) == NULL) || ((*stack_b) == NULL))
		err();
	(*stack_a) = (*stack_a)->prev;
	(*stack_b) = (*stack_b)->prev;
	ft_print_s("rrr\n");
}
