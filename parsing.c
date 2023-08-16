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
	t_list	*stack_a;
	t_str	*strings;

	strings = (t_str *)malloc(sizeof(t_str));
	strings->str = create_arg(argv);
	stack_a = create_stack(strings->str, stacks, len, strings);
	free(strings);
	return (stack_a);
}

char	*create_arg(char **argv)
{
	int		i;
	char	*str;
	char	*str_temp;

	str = ft_strdup("");
	i = 1;
	while (argv[i])
	{
		str_temp = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str_temp, " ");
		i++;
	}
	return (str);
}

t_list	*create_stack(char *str, t_stack *stacks, int *len, t_str *strings)
{
	t_list	*stack_a;
	t_list	*tmp;
	int		num;
	int		i;

	stack_a = NULL;
	strings->str_split = ft_split(str, ' ');
	if (check_args(strings->str_split) == 0)
	{
		write(2, "Error\n", 6);
		end(stacks, strings, len);
	}
	i = 0;
	while (strings->str_split[i])
	{
		num = (int)ft_push_atoi(strings->str_split[i], stacks, strings, len);
		tmp = ft_lstnew(num, 0);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	*len = i;
	free_str_arr(strings->str_split);
	free(str);
	return (stack_a);
}

int	arg_empty(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ' && argv[i][j])
		{
			j++;
			if (argv[i][j] == '\0')
				return (1);
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		if (argv[i] && !argv[i][0])
			return (1);
		i++;
	}
	return (0);
}
