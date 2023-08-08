/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:00:42 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/08 18:23:29 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_min(t_list *stack)
{
	int min = INT_MAX;
    t_list *list;
	
	list = stack;
    while (list != NULL) 
	{
        if (list->content < min)
            min = list->content;
        list = list->next;
    }
    return min;
}

int	find_max(t_list *stack)
{
	int max = INT_MIN;
    t_list *list;
	
	list = stack;
    while (list != NULL) 
	{
        if (list->content > max)
            max = list->content;
        list = list->next;
    }
    return max;
}

int is_sorted(t_list *list)
{
    t_list  *tmp;
    t_list	*rem;

	tmp = list;
	while (tmp && tmp->next)
	{
		rem = tmp->next;
		if (tmp->content > rem->content)
			return (0);
		tmp = tmp->next;
	}
    return (1);
}