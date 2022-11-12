/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:29:43 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/09 20:49:09 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_cdll	*create_node(int data)
{
	t_cdll	*node;

	node = malloc(sizeof(t_cdll));
	if (node == NULL)
		err();
	node->data = data;
	node->index = 0;
	node->prev = node;
	node->next = node;
	return (node);
}

void	add_front(t_cdll **current, t_cdll *new_node)
{
	(*current)->prev->next = new_node;
	new_node->prev = (*current)->prev;
	(*current)->prev = new_node;
	new_node->next = (*current);
	(*current) = new_node;
}

void	add_rear(t_cdll **current, t_cdll *new_node)
{
	t_cdll	*head;
	t_cdll	*tail;

	head = (*current);
	tail = (*current)->prev;
	tail->next = new_node;
	new_node->next = head;
	head->prev = new_node;
	new_node->prev = tail;
}

t_cdll	*get_node(t_cdll **head)
{
	t_cdll	*prev;
	t_cdll	*next;
	t_cdll	*target;

	target = (*head);
	prev = (*head)->prev;
	next = (*head)->next;
	target->prev = target;
	target->next = target;
	prev->next = next;
	next->prev = prev;
	(*head) = next;
	return (target);
}

void	list_cmp(t_cdll **front, t_cdll **rear)
{
	t_cdll	*front_temp;
	t_cdll	*rear_temp;

	front_temp = (*front);
	rear_temp = (*rear);
	(*front)->prev->next = NULL;
	(*rear)->prev->next = NULL;
	while ((*front))
	{
		while ((*rear))
		{
			if ((*front)->data == (*rear)->data)
				err();
			(*rear) = (*rear)->next;
		}
		(*rear) = rear_temp;
		(*front) = (*front)->next;
	}
	(*front) = front_temp;
	(*rear) = rear_temp;
	(*front)->prev->next = (*front);
	(*rear)->prev->next = (*rear);
}
