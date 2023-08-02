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
// void	free_list(t_list **root);
void	free_list(t_stack *bing_chilling);
void	insert_node(t_list **root, int num);
void	free_str_arr(char **str);
t_list	*parse_list(int argc, char **argv);
int		verify_args(char **argv);
t_list	*sab(t_list *root);
void	ss(t_list	*root_a, t_list	*root_b);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
t_list	*r_rab(t_list *root);
t_list	*rab(t_list	*root);
void	rr(t_stack *stacks);
void	rrr(t_stack *stacks);
void	sort_2(stack_t *stacks);

#endif