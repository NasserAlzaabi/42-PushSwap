/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:24:55 by naalzaab          #+#    #+#             */
/*   Updated: 2023/07/19 19:25:54 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*parse_list(char **argv, t_stack *stacks, int *len)
{
	int		i;
	t_list	*stack_a;
	t_list	*tmp;
	int		num;
	char	*str;
	char	*str_temp;
	char	**str_split;

	stack_a = NULL;
	str = ft_strdup("");
	i = 1;
	while (argv[i])
	{
		str_temp = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str_temp, " ");
		i++;
	}
	if (only_spaces(str) == 1)
		end (stacks, NULL, str, NULL);
	str_split = ft_split(str, ' ');
	if (check_args(str_split) == 0)
	{
		write(1, "Error\n", 7);
		end(stacks, str_split, str, NULL);
	}
	i = 0;
	while (str_split[i])
	{
		num = ft_atoi(str_split[i]);
		tmp = ft_lstnew(num, 0);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	*len = i;
	return (free(str), free_str_arr(str_split), stack_a);
}
