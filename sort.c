/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:24:22 by naalzaab          #+#    #+#             */
/*   Updated: 2023/07/11 21:15:23 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_2(t_stack *stacks)
{
	if (!stacks || !stacks->stack_a->next)
		return ;
	if (stacks->stack_a->content > stacks->stack_a->next->content)
		stacks->stack_a = (stacks->stack_a);
}

// void	sort_3(t_stack *stacks)
// {
// 	int	one;
// 	int	two;
// 	int three;

// 	one = stacks->stack_a->content;
// 	two = stacks->stack_a->next->content;
// 	three = stacks->stack_a->next->next->content;
// }

// int	*sort_4()
// {

// }

// int	*sort_5()
// {

// }