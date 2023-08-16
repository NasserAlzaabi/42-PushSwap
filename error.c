/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:46:14 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/16 18:35:58 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_args(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != '-')
				return (0);
			if (str[i][j] == '-' && !str[i][j + 1])
				return (0);
			j++;
		}
		if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
			return (0);
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
		if (tmp->content > INT_MAX || tmp->content < INT_MIN)
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

void	end(t_stack *stacks, t_str *strings, int *len)
{
	if (strings)
	{
		if (strings->str)
			free(strings->str);
		if (strings->str_split)
			free_str_arr(strings->str_split);
		free (strings);
	}
	if (stacks)
	{
		if (stacks->stack_a || stacks->stack_b)
			free_list(stacks);
		free(stacks);
	}
	if (len)
		free(len);
	exit(1);
}

int	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
