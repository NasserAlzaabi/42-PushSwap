/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:37:06 by naalzaab          #+#    #+#             */
/*   Updated: 2023/08/14 23:26:59 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_push_atoi(const char *str, t_stack *st, t_str *strings, int *l)
{
	int					i;
	unsigned long long	x;
	int					s;
	int					n;

	s = 1;
	i = 0;
	x = 0;
	while (space(str[i]))
		i++;
	while (str[i] == '-' && ++i)
		s *= -1;
	while (str[i] == '+')
		i++;
	n = i;
	while (str[n] >= '0' && str[n] <= '9')
	{
		x = x * 10 + (str[n++] - 48);
		if ((x > 2147483647ULL && s == 1) || ((x > 2147483648ULL && s == -1)))
		{
			write(2, "Error\n", 6);
			end(st, strings, l);
		}
	}
	return (x * s);
}
