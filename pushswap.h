/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:22:21 by naalzaab          #+#    #+#             */
/*   Updated: 2023/07/19 20:27:55 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "./Libft/libft.h"

typedef	struct lists
{
	int				nbr;
	struct lists	*next;
	struct lists	*prev;
}	list;

void	insert_node(list **root, int num);
void	free_list(list **root);
void	insert_node(list **root, int num);
void	free_str_arr(char **str);

#endif