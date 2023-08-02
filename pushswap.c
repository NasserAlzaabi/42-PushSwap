/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:45:19 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/02 19:38:17 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void	free_b(t_list *bing_chilling) {
// 	t_list *b_gae = bing_chilling;
// 	t_list *tmp;
	
// 	while (b_gae) {
// 		tmp = b_gae->next;
// 		// free(b_gae->content);
// 		free (b_gae);
// 		b_gae = tmp;
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	stacks = (t_stack *)malloc(sizeof(t_stack));
	stacks->stack_b = NULL;
	stacks->stack_a = parse_list(argc, argv);

	ss(stacks->stack_a, stacks->stack_b);
	stacks->stack_a = sab(stacks->stack_a);
	pb(stacks);
	pb(stacks);
	pb(stacks);

	t_list	*a;
	t_list	*b;
	
	stacks->stack_a = rab(stacks->stack_a);
	stacks->stack_b = r_rab(stacks->stack_b);
	rr(stacks);
	rrr(stacks);
	a = stacks->stack_a;
	b = stacks->stack_b;
	while (b != NULL)
	{
		printf("num b: %d\n", b->content);
		b = b->next;
	}
	printf("\n");
	while (a != NULL)
	{
		printf("num a: %d\n", a->content);
		a = a->next;
	}
	free_list(stacks);
	// free_list(&stacks->stack_b);
	// free_b(&b);
	free(stacks);
}
