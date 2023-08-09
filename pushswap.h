/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:22:21 by naalzaab          #+#    #+#             */
/*   Updated: 2023/07/19 20:27:55 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "./Libft/libft.h"

typedef struct s_stack
{
	t_list *stack_a;
	t_list *stack_b;
}	t_stack;


void	insert_node(t_list **root, int num);
void	free_list(t_stack *root);
void	insert_node(t_list **root, int num);
void	free_str_arr(char **str);
t_list	*parse_list(char **argv/*, t_stack *stacks*/);
int		verify_args(t_stack *stacks);
int		has_dupes(t_stack *stacks);
t_list	*sab(t_list *root, t_stack *stacks, int sab_flag);
void	ss(t_list	*root_a, t_list	*root_b, t_stack *stacks);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
t_list	*r_rab(t_list *root, t_stack *stacks, int r_rab_flag);
t_list	*rab(t_list	*root, t_stack *stacks, int rab_flag);
void	rr(t_stack *stacks);
void	rrr(t_stack *stacks);
void	sort_2(t_stack *stacks);
void	sort_3(t_stack *stacks);
void	sort_4(t_stack *stacks);
void	sort_5(t_stack *stacks);
void	end(t_stack *stacks, char **str_split, char *str);
int		ft_stack_atoi(const char *str, t_stack *stacks, char **str_split, char *s_str);
void	sort_all(int argc, t_stack *stacks);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		is_sorted(t_list *list);
void	radix_sort(t_stack *stacks, int len);
void	counting_sort_a(t_stack *stacks, int multiple);
void	counting_sort_b(t_stack *stacks, int multiple);
int		count_digit(t_list *list, int digit, int multiple);
int		check_args(char **str);
void	sort_index(t_stack *stacks, int len);
void	bubble_sort(int *arr, int len);
int		find_max_bit(t_stack *stacks);

#endif