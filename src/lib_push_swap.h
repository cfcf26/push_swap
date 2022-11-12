/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:18:10 by ekwak             #+#    #+#             */
/*   Updated: 2022/11/09 20:51:26 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H
# define INTMAX 2147483647
# define INTMIN -2147483648
# include <stdlib.h> //malloc, free
# include <unistd.h>

typedef struct s_cdll
{
	int				data;
	int				index;
	struct s_cdll	*prev;
	struct s_cdll	*next;
}	t_cdll;
//error
void	err(void);
//libft
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *src);
/*ft_printf*/
int		ft_print_c(int c); // %c
int		ft_print_s(char *str); // %s
/*input to string*/
char	*ft_itoa_f(int n);
//lib_push_swap
int		ft_atoi_ps(const char *str);
t_cdll	*create_node(int data);
void	add_front(t_cdll **current, t_cdll *new_node);
void	add_rear(t_cdll **current, t_cdll *new_node);
t_cdll	*get_node(t_cdll **node);
void	list_cmp(t_cdll **front, t_cdll **rear);
void	connect_list(t_cdll **front, t_cdll **rear);
t_cdll	*set_list(char **arr);
int		lst_len(t_cdll **lst);
//swap
void	sa(t_cdll **head);
void	sb(t_cdll **head);
void	ss(t_cdll **head_a, t_cdll **head_b);
//push
void	pa(t_cdll **head_a, t_cdll **head_b);
void	pb(t_cdll **head_b, t_cdll **head_a);
//rotate
void	ra(t_cdll **head_a);
void	rb(t_cdll **head_b);
void	rr(t_cdll **head_a, t_cdll **head_b);
//reserve rotate
void	rra(t_cdll **head_a);
void	rrb(t_cdll **head_b);
void	rrr(t_cdll **head_a, t_cdll **head_b);
#endif