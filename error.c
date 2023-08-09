/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:46:14 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/09 21:49:29 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int	ft_stack_atoi(const char *str, t_stack *stacks, char **str_split, char *s_str)
// {
// 	int	i;
// 	int	x;
// 	int	s;
// 	int	n;

// 	s = 1;
// 	i = 0;
// 	x = 0;
// 	while (space(str[i]))
// 		i++;
// 	while (str[i] == '-' && ++i)
// 		s *= -1;
// 	while (str[i] == '+')
// 		i++;
// 	n = i;
// 	while (str[i])
// 	{
// 		if (!(str[i] >= '0' && str[i] <= '9'))
// 			end(stacks, str_split, s_str);
// 		i++;
// 	}
// 	while (str[n] >= '0' && str[n] <= '9')
// 		x = x * 10 + (str[n++] - 48);
// 	return (x * s);
// }

int	check_args(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verify_args(t_stack *stacks)
{
	t_list	*tmp;

	tmp = stacks->stack_a;
	if (has_dupes(stacks))
		return (0);
	while (tmp)
	{
		if (tmp->content > 2147483647 || tmp->content < -2147483647)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	has_dupes(t_stack *stacks)
{
	t_list	*list;
	t_list	*rem;
	
	list = stacks->stack_a;
	while (list->next)
	{
		rem = list->next;
		while (rem)
		{
			if (list->content == rem->content)
				return (1);
			rem = rem->next;
		}
		list = list->next;
	}
	return (0);
}

void end(t_stack *stacks, char **str_split, char *str)
{
	if (str)
		free(str);
	if (str_split)
		free_str_arr(str_split);	
	if (stacks)
	{
		free_list(stacks);
		free(stacks);
	}
	exit(1);
}