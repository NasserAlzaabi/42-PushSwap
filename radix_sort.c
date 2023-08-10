/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:11:45 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/10 14:49:40 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	radix_sort(t_stack *stacks, int len)
{
	int	max_bit;
	int	bit;
	int	i;
	int mask;
	int len_a;
	int len_b;
	
	sort_index(stacks, len);
	max_bit = find_max_bit(stacks);
	bit = 0;
	while (bit < max_bit)
	{
		mask = 1 << bit;
		len_b = list_length(stacks->stack_b);
		len_a = list_length(stacks->stack_a);
		i = 0;
		// t_list *tmp;
		// tmp = stacks->stack_a;
		// while (tmp)
		// {
		// 	printf("index a: %d\n", tmp->index);
		// 	tmp = tmp->next;
		// }
		// tmp = stacks->stack_b;
		// while (tmp)
		// {
		// 	printf("index b: %d\n", tmp->index);
		// 	tmp = tmp->next;
		// }
		while (i < len_b)
		{
			if ((stacks->stack_b->index & mask) == 0)
				stacks->stack_b = rab(stacks->stack_b, stacks, 1);
			else
			{
				pa(stacks);
				stacks->stack_a = rab(stacks->stack_a, stacks, 1);
			}
			i++;
		}
		i = 0;
		while (i < len_a)
		{
			if ((stacks->stack_a->index & mask) == 0)
			{
				pb(stacks);
				stacks->stack_b = rab(stacks->stack_b, stacks, 1);
			}
			else
				stacks->stack_a = rab(stacks->stack_a, stacks, 1);
			i++;
		}
		// while (stacks->stack_b)
		// 	pa(stacks);
		bit++;
	}
	while (stacks->stack_b && stacks->stack_b->next)
	{
		stacks->stack_b = r_rab(stacks->stack_b, stacks, 1);
		pa(stacks);
	}
	//pa(stacks);
}

void	sort_index(t_stack *stacks, int len)
{
	int *arr;
	t_list *tmp;
	int	i;
	
	i = 0;
	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return ;
	tmp = stacks->stack_a;
	while (tmp)
	{
		arr[i] = tmp->content;
		i++;
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

// void	counting_sort_a(t_stack *stacks, int multiple)
// {
// 	int	count;
// 	int digit;
// 	int	rem;
	
// 	rem = multiple/10;
// 	digit = 0;
// 	while (digit <= 9)
// 	{
// 		count = count_digit(stacks->stack_a, digit,multiple);
// 		while (count > 0)
// 		{
// 			if ((stacks->stack_a->content % multiple) - (stacks->stack_a->content % rem) == digit*(rem))
// 			{
// 				pb(stacks);
// 				count--;
// 			}
// 			stacks->stack_a = rab(stacks->stack_a, stacks, 1);
// 		}
// 		digit++;
// 	}
// }

// void	counting_sort_b(t_stack *stacks, int multiple)
// {
// 	int	count;
// 	int digit;
// 	int	rem;
	
// 	rem = multiple/10;
// 	digit = 0;
// 	while (digit <= 9)
// 	{
// 		count = count_digit(stacks->stack_b, digit, multiple);
// 		while (count > 0)
// 		{
// 			if ((stacks->stack_b->content % multiple) - (stacks->stack_b->content % rem) == digit*(rem))
// 			{
// 				pa(stacks);
// 				count--;
// 			}
// 			stacks->stack_b = rab(stacks->stack_b, stacks, 1);
// 		}
// 		digit++;
// 	}
// }

// int	count_digit(t_list *list, int digit, int multiple)
// {
// 	t_list	*tmp;
// 	int	count;
// 	int	rem;
	
// 	rem = multiple/10;
// 	tmp = list;
// 	count = 0;
// 	if (digit == 0)
// 		digit = multiple;
// 	else
// 		digit = digit*rem;
// 	while (tmp)
// 	{
// 		if (((tmp->content % multiple) - tmp->content % rem) == digit)
// 			count++;
// 		tmp = tmp->next;
// 	}
// 	return (count);
// }