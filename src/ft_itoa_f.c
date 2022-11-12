/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:00:39 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/02 19:46:27 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void	ft_rev_char_tab(char *tab, int size)
{
	int	i;
	int	rev_tab;

	i = 0;
	while (i < (size / 2))
	{
		rev_tab = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = rev_tab;
		i++;
	}
}

static char	*ft_itoa_2(unsigned int n, int flag)
{
	char	str[12];
	int		i;
	char	*dup;

	i = 0;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (flag == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	ft_rev_char_tab(str, i);
	dup = ft_strdup(str);
	return (dup);
}

char	*ft_itoa_f(int n)
{
	int		flag;

	flag = 0;
	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	else if (n < 0)
	{
		n *= -1;
		flag = 1;
	}
	return (ft_itoa_2((unsigned int)n, flag));
}
