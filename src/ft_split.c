/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:40:35 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/07 14:49:44 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static	size_t	w_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	char	*w_dup(char	const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		err();
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static char	**ft_dosplit(char const *s, char c, const size_t w_con, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < w_con && s[j])
	{
		if (s[j] != c)
		{
			str[i] = w_dup(&(s[j]), c);
			if (str[i] == NULL)
				err();
			while (s[j] && s[j] != c)
				j++;
			i++;
		}
		else
			j++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	const size_t	w_con = w_count(s, c);

	str = malloc(sizeof(char *) * (w_con + 1));
	if (str == NULL || s[0] == '\0')
		err();
	ft_dosplit(s, c, w_con, str);
	if (str[0] == NULL)
		err();
	return (str);
}
