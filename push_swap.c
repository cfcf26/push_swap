/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:09:45 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/12 19:24:42 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/push_swap.h"

static void	check_sort(t_cdll **stack)
{
	int		i;
	t_cdll	*temp;

	i = 1;
	temp = (*stack);
	temp->prev->next = NULL;
	while (temp)
	{
		if (temp->index != i)
		{
			(*stack)->prev->next = (*stack);
			return ;
		}
		i++;
		temp = temp->next;
	}
	exit(0);
}

static int	make_chunk(int len)
{
	int	chunk;

	chunk = (0.045 * len) + 10.75;
	if (len < 30)
		chunk = 1;
	else if (len >= 500)
		chunk = 32;
	return (chunk);
}

int	main(int argc, char *argv[])
{
	t_cdll	*stack_a;
	t_cdll	*stack_b;
	int		len;

	if (argc < 2)
		exit(0);
	stack_b = NULL;
	stack_a = set_stack(argv);
	len = lst_len(&stack_a);
	check_sort(&stack_a);
	if (len == 2)
		sa(&stack_a);
	else if (len == 3)
		sort_3(&stack_a, 3);
	else if (len == 4)
		sort_4(&stack_a, &stack_b);
	else if (len == 5)
		sort_5(&stack_a, &stack_b);
	else
		sort(&stack_a, &stack_b, make_chunk(len), len);
	exit(0);
}
