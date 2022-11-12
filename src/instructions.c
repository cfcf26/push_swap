/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:58:36 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/09 19:08:40 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	sa(t_cdll **stack_a)
{
	if ((*stack_a) == NULL)
		return ;
	add_front(stack_a, get_node(&((*stack_a)->next)));
	ft_print_s("sa\n");
}

void	sb(t_cdll **stack_b)
{
	if ((*stack_b) == NULL)
		return ;
	add_front(stack_b, get_node(&((*stack_b)->next)));
	ft_print_s("sb\n");
}

void	ss(t_cdll **stack_a, t_cdll **stack_b)
{
	if (((*stack_a) == NULL) || ((*stack_b) == NULL))
		err();
	add_front(stack_a, get_node(&((*stack_a)->next)));
	add_front(stack_b, get_node(&((*stack_b)->next)));
	ft_print_s("ss\n");
}

void	pa(t_cdll **stack_a, t_cdll **stack_b)
{
	if ((*stack_b) == NULL)
	{
		ft_print_s("pa\n");
		return ;
	}
	if ((*stack_a) == NULL)
	{
		(*stack_a) = get_node(stack_b);
		(*stack_a)->next = (*stack_a);
		(*stack_a)->prev = (*stack_a);
	}
	else if ((*stack_b)->next == (*stack_b))
	{
		add_front(stack_a, (*stack_b));
		(*stack_b) = NULL;
	}
	else
		add_front(stack_a, get_node(stack_b));
	ft_print_s("pa\n");
	return ;
}

void	pb(t_cdll **stack_b, t_cdll **stack_a)
{
	if ((*stack_a) == NULL)
	{
		ft_print_s("pb\n");
		return ;
	}
	if ((*stack_b) == NULL)
	{
		(*stack_b) = get_node(stack_a);
		(*stack_b)->next = (*stack_b);
		(*stack_b)->prev = (*stack_b);
	}
	else if ((*stack_a)->next == (*stack_a))
	{
		add_front(stack_b, (*stack_a));
		(*stack_a) = NULL;
	}
	else
		add_front(stack_b, get_node(stack_a));
	ft_print_s("pb\n");
	return ;
}
