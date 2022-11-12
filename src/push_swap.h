/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:12:54 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/10 15:44:53 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "lib_push_swap.h"

void	sort_b(t_cdll **stack_b, int len);
void	sort(t_cdll **stack_a, t_cdll **stack_b, int chunk, int len);
t_cdll	*set_stack(char *argv[]);
void	sort_3(t_cdll **stack, int size);
void	sort_4(t_cdll **stack_a, t_cdll	**stack_b);
void	sort_5(t_cdll **stack_a, t_cdll	**stack_b);
#endif
