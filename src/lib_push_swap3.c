/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:06:34 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/09 19:07:55 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	lst_len(t_cdll **lst)
{
	int		len;
	t_cdll	*node;

	len = 0;
	node = (*lst);
	node->prev->next = NULL;
	while (node)
	{
		node = node->next;
		len++;
	}
	(*lst)->prev->next = (*lst);
	return (len);
}
