/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:27:23 by naalzaab          #+#    #+#             */
/*   Updated: 2023/07/23 20:27:23 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void	free_list(t_list **root)
// {
// 	t_list	*tmp;

// 	if (*root == NULL)
// 		return ;
// 	tmp = *root;
// 	while (*root != NULL)
// 	{
// 		tmp = (*root)->next;
// 		if (*root)
// 			free (*root);
// 		*root = tmp;
// 	}
// }

void	free_list(t_stack *root)
{
	t_list *list_a = root->stack_a;
	t_list *list_b = root->stack_b;
	t_list *tmp;

	while (list_a) {
		tmp = list_a->next;
		free (list_a);
		list_a = tmp;
	}
	while (list_b) {
		tmp = list_b->next;
		free (list_b);
		list_b = tmp;
	}
}

void	free_str_arr(char** str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}