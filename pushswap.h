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

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "./Libft/libft.h"

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

typedef struct s_str
{
	char	*str;
	char	**str_split;
}	t_str;

void	free_list(t_stack *root);
void	free_str_arr(char **str);
t_list	*parse_list(char **argv, t_stack *stacks, int *len);
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
void	end(t_stack *stacks, t_str *strings, int *len);
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
int		list_length(t_list *list);
int		find_max_index(t_list *stack);
int		only_spaces(char *str);
int		arg_empty(char **argv);
t_list	*create_stack(char *str, t_stack *stacks, int *len, t_str *strings);
char	*create_arg(char **argv);
int		get_min_pos(t_list *stack_a, int min);
int		ft_push_atoi(const char *str, t_stack *st, t_str *strings, int *len);

#endif