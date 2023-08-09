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

t_list	*parse_list(char **argv/*, t_stack *stacks*/)
{
	int		i;
	t_list	*stack_a;
	t_list	*tmp;
	int		num;
	char	*str;
	char	*str_temp;
	char	**str_split;

	stack_a = NULL;
	str = ft_strdup(""); // Initialize str as an empty string
	i = 1;
	while (argv[i])
	{
		str_temp = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str_temp, " ");
		i++;
	}
	str_split = ft_split(str, ' ');
	if (check_args(str_split) == 0)
	{
		write(1, "Error", 6);
		end(NULL, str_split, str);
	}
	i = 0;
	while (str_split[i])
	{
		num = ft_atoi(str_split[i]/*, stacks, str_split, str*/);
		tmp = ft_lstnew(num);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	return (free(str), free_str_arr(str_split), stack_a);
}

