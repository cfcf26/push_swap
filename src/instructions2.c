/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 00:55:10 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/09 19:31:48 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ra(t_cdll **stack_a)
{
	if ((*stack_a) == NULL)
		err();
	(*stack_a) = (*stack_a)->next;
	ft_print_s("ra\n");
}

void	rb(t_cdll **stack_b)
{
	if ((*stack_b) == NULL)
		err();
	(*stack_b) = (*stack_b)->next;
	ft_print_s("rb\n");
}

void	rr(t_cdll **stack_a, t_cdll **stack_b)
{
	if (((*stack_a) == NULL) || ((*stack_b) == NULL))
		err();
	(*stack_a) = (*stack_a)->next;
	(*stack_b) = (*stack_b)->next;
	ft_print_s("rr\n");
}
