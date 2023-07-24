/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:45:19 by naalzaab          #+#    #+#             */
/*   Updated: 2023/07/20 19:55:37 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*parse_list(int	argc, char	**argv)
{
	int 	i;
	char	*str;
	char	**split_str;
	t_list	*stack_a;
	
	i = 1;
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	split_str = ft_split(str, ' ');
	//check if input is valid (no letters repeat nums etc)
	int n;
	n = argc;
	//tmp
	stack_a = ft_lstnew(atoi(split_str[0]));
	i = 1;
	while (str[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(split_str[i])));
		i++;
	}
	
	
	return (free(str), free_str_arr(split_str), stack_a);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	//list	*stack_b;
	

	stack_a = parse_list(argc, argv);
	while (stack_a -> next != NULL)
		printf("num: %d\n", stack_a -> content);
	
}

// void insert_node(list **root, int num)
// {
// 	list *tmp;

// 	tmp = malloc(sizeof(list));
// 	tmp -> nbr = num;
// 	tmp -> next = *root;
// 	*root = tmp;
// }
