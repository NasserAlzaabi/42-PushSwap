/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:45:19 by naalzaab          #+#    #+#             */
/*   Updated: 2023/07/25 18:57:28 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*parse_list(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	int		num;
	char	*str;
	char	*str_temp;
	char	**str_split;

	stack_a = NULL;
	if (argc < 2)
		exit(1);
	
	str = ft_strdup(""); // Initialize str as an empty string

	i = 1;
	while (argv[i])
	{
		str_temp = ft_strjoin(str, argv[i]);
		// free(str); // Free the previous str
		str = ft_strjoin(str_temp, " ");
		// free(str_temp); // Free the temporary result
		i++;
	}

	str_split = ft_split(str, ' ');
	// free(str);
	// if (verify_args(argc, str_split) != 1) //fix
	// 	return (write(1,"invalid args", 13),NULL);
	i = 0;
	while (str_split[i])
	{
		num = ft_atoi(str_split[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(num));
		i++;
	}
	return (free(str), free_str_arr(str_split), stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = parse_list(argc, argv);
	while (stack_a != NULL)
	{
		printf("num: %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}


// void insert_node(list **root, int num)
// {
// 	list *tmp;

// 	tmp = malloc(sizeof(list));
// 	tmp -> nbr = num;
// 	tmp -> next = *root;
// 	*root = tmp;.
// }
