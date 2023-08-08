/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:11:45 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/08 20:11:38 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	radix_sort(t_stack *stacks)
{
	int	multiple;
	int	max;

	max = find_max(stacks->stack_a);
	multiple = 10;
	while (!is_sorted(stacks->stack_a))
	{
		counting_sort_a(stacks, multiple);
		multiple *= 10;
		counting_sort_b(stacks, multiple);
	}
}

void	counting_sort_a(t_stack *stacks, int multiple)
{
	int	count;
	int digit;
	int	rem;
	
	rem = multiple/10;
	digit = 0;
	while (digit <= 9)
	{
		count = count_digit(stacks->stack_a, digit,multiple);
		while (count > 0)
		{
			if ((stacks->stack_a->content % multiple) - (stacks->stack_a->content % rem)== digit*(rem))
			{
				pb(stacks);
				count--;
			}
			stacks->stack_a = rab(stacks->stack_a, stacks, 1);
		}
		digit++;
	}
}

void	counting_sort_b(t_stack *stacks, int multiple)
{
	int	count;
	int digit;
	int	rem;
	
	rem = multiple/10;
	digit = 0;
	while (digit <= 9)
	{
		count = count_digit(stacks->stack_b, digit,multiple);
		while (count > 0)
		{
			if ((stacks->stack_b->content % multiple) - (stacks->stack_b->content % rem) == digit*(rem))
			{
				pa(stacks);
				count--;
			}
			stacks->stack_b = rab(stacks->stack_b, stacks, 1);
		}
		digit++;
	}
}

int	count_digit(t_list *list, int digit, int multiple)
{
	t_list	*tmp;
	int	count;
	int	remainder;
	
	remainder = multiple/10;
	tmp = list;
	count = 0;
	while (tmp)
	{
		if (((tmp->content % multiple) - tmp->content % remainder ) == digit)
			count++;
		tmp = tmp->next;
	}
	return (count);
}