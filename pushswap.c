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

int main(int argc, char **argv)
{
	list	*stack_a;
	//list	*stack_b;
	int 	i;
	//int		x;

	stack_a = malloc(sizeof(list));
	if (stack_a == NULL)
		return(0);
	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		insert_node(&stack_a, atoi(argv[i]));
		stack_a = stack_a -> next;
		i++;
	}

	while (stack_a -> next != NULL)
		printf("num: %d\n", stack_a -> nbr);
	
}

void insert_node(list **root, int num)
{
	list *tmp;

	tmp = malloc(sizeof(list));
	tmp -> nbr = num;
	tmp -> next = *root;
	*root = tmp;
}
