/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:15:25 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/02 19:35:49 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*src_dup;

	src_dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (src_dup == NULL)
	{
		free(src_dup);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		src_dup[i] = src[i];
		i++;
	}
	src_dup[i] = '\0';
	return (src_dup);
}
