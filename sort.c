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
		stacks->stack_a = sab(stacks->stack_a, stacks, 1);
}

void	sort_3(t_stack *stacks)
{
	int	one;
	int	two;
	int three;

	one = stacks->stack_a->content;
	two = stacks->stack_a->next->content;
	three = stacks->stack_a->next->next->content;
	if (one > two && two < three && one < three)
		stacks->stack_a = sab(stacks->stack_a, stacks, 1);
	else if (one > two && two > three && one > three)
	{
		stacks->stack_a = sab(stacks->stack_a, stacks, 1);
		stacks->stack_a = r_rab(stacks->stack_a, stacks, 1);
	}
	else if (one > two && two < three && three < one)
		stacks->stack_a = rab(stacks->stack_a, stacks, 1);
	else if (one < two && two > three && three > one)
	{
		stacks->stack_a = sab(stacks->stack_a, stacks, 1);
		stacks->stack_a = rab(stacks->stack_a, stacks, 1);
	}
	else if (one < two && two > three && one > three)
		stacks->stack_a = r_rab(stacks->stack_a, stacks, 1);
}

void	sort_4(t_stack *stacks)
{
	int	min;

	if (is_sorted(stacks->stack_a))
		return ;
	min = find_min(stacks->stack_a);
	while (stacks->stack_a->content != min)
		stacks->stack_a = r_rab(stacks->stack_a, stacks, 1);
	pb(stacks);
	sort_3(stacks);
	pa(stacks);
}

void	sort_5(t_stack *stacks) //need to improve to make less than 12 moves
{
	int	min;

	if (is_sorted(stacks->stack_a))
		return ;
	min = find_min(stacks->stack_a);
	while (stacks->stack_a->content != min)
		stacks->stack_a = r_rab(stacks->stack_a, stacks, 1);
	pb(stacks);
	sort_4(stacks);
	pa(stacks);
	// min = find_min(stacks->stack_a);
	// while (stacks->stack_a->content != min)
	// 	stacks->stack_a = rab(stacks->stack_a, stacks, 1);
	// pb(stacks);
	// sort_3(stacks);
	// pa(stacks);
	// pa(stacks);
}

void	sort_all(int argc, t_stack *stacks)
{
	if (is_sorted(stacks->stack_a))
		return ;
	if (argc == 2)
		sort_2(stacks);
	else if (argc == 3)
		sort_3(stacks);
	else if (argc == 4)
		sort_4(stacks);
	else if (argc == 5)
		sort_5(stacks);
	else if (argc > 5)
		radix_sort(stacks, argc);
}