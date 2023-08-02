/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:32:56 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/02 19:48:08 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*rab(t_list	*root)
{
	t_list *tmp;
    t_list *second;

    tmp = root;
    if (!tmp || !root)
        return NULL;
    second = root->next;
    if (!second)
        return root;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = root;
    root->next = NULL;

    return second;
}

void	rr(t_stack *stacks)
{
	if (stacks->stack_a)
		stacks->stack_a = rab(stacks->stack_a);
	if (stacks->stack_b)
		stacks->stack_b = rab(stacks->stack_b);
	write(1, "rr\n", 4);
}

t_list	*r_rab(t_list *root)
{
	t_list	*tmp;
	t_list	*first;
	
	
	tmp = root;
	if (!tmp || !root)
		return (NULL);
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	first = tmp->next;
	tmp->next = NULL;
	
	first->next = root;
	//tmp->next = root;
	return (first);
}

void	rrr(t_stack *stacks)
{
	if (stacks->stack_a)
		stacks->stack_a = r_rab(stacks->stack_a);
	if (stacks->stack_b)
		stacks->stack_b = r_rab(stacks->stack_b);
	write(1, "rrr\n", 5);
}