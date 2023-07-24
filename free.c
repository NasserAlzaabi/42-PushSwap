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

void	free_list(list **root)
{
	list *r;
	list *tmp;
	r = *root;
	while (r != NULL)
	{
		tmp = r;
		r = r -> next;
		free(tmp);
	}
	*root = NULL;
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