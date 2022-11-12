/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:59:15 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/12 18:55:43 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_for_indexing(t_cdll **lst, int len)
{
	t_cdll			*node;
	t_cdll			*max_node;
	long long		max;

	node = (*lst);
	node->prev->next = NULL;
	while (len > 0)
	{
		max = INTMIN - 1;
		node = (*lst);
		while (node)
		{
			if (node->data > max && node->index < len)
			{
				max = (long long)node->data;
				max_node = node;
			}
			node = node->next;
		}
		max_node->index = len;
		len--;
	}
	(*lst)->prev->next = (*lst);
}

t_cdll	*set_stack(char *argv[])
{
	t_cdll	*front_head;
	t_cdll	*rear_head;
	int		i;
	int		len;

	i = 2;
	front_head = set_list(ft_split(argv[1], ' '));
	while (argv[i])
	{
		rear_head = set_list(ft_split(argv[i], ' '));
		list_cmp(&front_head, &rear_head);
		connect_list(&front_head, &rear_head);
		i++;
	}
	len = lst_len(&front_head);
	sort_for_indexing(&front_head, len);
	if (len < 2)
		exit(0);
	return (front_head);
}
