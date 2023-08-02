/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:13:39 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/02 20:16:25 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*sab(t_list *root, t_stack *stacks, int sab_flag)
{
	int	tmp;

	if (stacks->stack_a == root && sab_flag == 1)
		write(1, "sa\n", 4);
	else if (stacks->stack_b == root && sab_flag == 1)
		write(1, "sb\n", 4);
	tmp = root->content;
	root->content = root->next->content;
	root->next->content = tmp;
	return (root);
}

void	ss(t_list	*root_a, t_list	*root_b, t_stack *stacks) // use t_stack if needed
{
	if (root_a)
		root_a = sab(root_a, stacks, 0);
	if (root_b)
		root_b = sab(root_b, stacks, 0);
	write(1, "ss\n", 4);
}

void	pa(t_stack *stacks)
{
	t_list	*tmp;
	t_list	*tmp_b;
	
	tmp = ft_lstnew(stacks->stack_b->content);
	tmp_b = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
    ft_lstadd_front(&stacks->stack_a, tmp);
	free(tmp_b);
	write(1, "pa\n", 4);
}

void	pb(t_stack *stacks)
{
	t_list	*tmp;
	t_list	*tmp_a;

	tmp = ft_lstnew(stacks->stack_a->content);
	tmp_a = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
    ft_lstadd_front(&stacks->stack_b, tmp); 
	free(tmp_a);
	write(1, "pb\n", 4);
}