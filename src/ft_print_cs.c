/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:23:09 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/02 19:31:21 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_print_s("(null)"));
	while (str[i])
		i += ft_print_c(str[i]);
	return (i);
}
