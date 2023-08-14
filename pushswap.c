/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:45:19 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/14 20:03:23 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		*len;

	if (arg_empty(argv) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stacks = (t_stack *)malloc(sizeof(t_stack));
	stacks->stack_b = NULL;
	stacks->stack_a = NULL;
	len = (int *)malloc(sizeof(int));
	stacks->stack_a = parse_list(argv, stacks, len);
	if (argc < 2)
		end(stacks, NULL, NULL, len);
	if (!verify_args(stacks))
	{
		write(2, "Error\n", 6);
		end(stacks, NULL, NULL, len);
	}
	sort_all(*len, stacks);
	free(len);
	free_list(stacks);
	free(stacks);
}
