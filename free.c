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

void	free_list(t_stack *bing_chilling) {
	t_list *a_gae = bing_chilling->stack_a;
	t_list *b_gae = bing_chilling->stack_b;
	t_list *tmp;

	while (a_gae) {
		tmp = a_gae->next;
		free (a_gae);
		a_gae = tmp;
	}
	while (b_gae) {
		tmp = b_gae->next;
		free (b_gae);
		b_gae = tmp;
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