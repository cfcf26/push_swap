/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:51:22 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/10 15:49:29 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	connect_list(t_cdll **front, t_cdll **rear)
{
	t_cdll	*front_head;
	t_cdll	*front_tail;
	t_cdll	*rear_head;
	t_cdll	*rear_tail;

	front_head = (*front);
	front_tail = (*front)->prev;
	rear_head = (*rear);
	rear_tail = (*rear)->prev;
	front_tail->next = rear_head;
	rear_tail->next = front_head;
	front_head->prev = rear_tail;
	rear_head->prev = front_tail;
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_cdll	*set_list(char **arr)
{
	t_cdll	*head;
	t_cdll	*tail;
	int		i;

	head = create_node(ft_atoi_ps(arr[0]));
	i = 1;
	while (arr[i])
	{
		tail = create_node(ft_atoi_ps(arr[i]));
		if (tail == NULL)
			err();
		add_rear(&head, tail);
		i++;
	}
	ft_free(arr);
	return (head);
}

int	ft_atoi_ps(const char *str)
{
	long	num;
	int		flag;
	int		i;

	i = 0;
	num = 0;
	flag = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	if (str[i] == '\0')
		err();
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= flag;
	if ((num < INTMIN || num > INTMAX) || (str[i] != '\0'))
		err();
	return (num);
}
