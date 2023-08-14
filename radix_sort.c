/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:11:45 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/14 20:54:11 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	radix_sort(t_stack *stacks, int len)
{
	int	max_bit;
	int	bit;
	int	i;
	int	mask;

	sort_index(stacks, len);
	max_bit = find_max_bit(stacks);
	bit = 0;
	while (bit < max_bit)
	{
		mask = 1 << bit;
		i = 0;
		while (i < len)
		{
			if ((stacks->stack_a->index & mask) == 0)
				pb(stacks);
			else
				stacks->stack_a = rab(stacks->stack_a, stacks, 1);
			i++;
		}
		while (stacks->stack_b)
			pa(stacks);
		bit++;
	}
}

void	sort_index(t_stack *stacks, int len)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	i = 0;
	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return ;
	tmp = stacks->stack_a;
	while (tmp)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	bubble_sort(arr, len);
	tmp = stacks->stack_a;
	while (tmp)
	{
		i = 0;
		while (arr[i] != tmp->content)
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
	free(arr);
}

void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_max_bit(t_stack *stacks)
{
	int		i;
	int		max;

	max = find_max_index(stacks->stack_a);
	i = 0;
	while (max > 0)
	{
		max = max >> 1;
		i++;
	}
	return (i);
}

int	get_min_pos(t_list *stack_a, int min)
{
	int		pos;
	t_list	*tmp;

	pos = 1;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content == min)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}
