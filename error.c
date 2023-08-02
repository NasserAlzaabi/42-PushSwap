/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:46:14 by naalzaab          #+#    #+#             */
/*   Updated: 2023/07/26 19:35:11 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	verify_args(char **argv)
{
	int	i;
	int x;
	
	x = 0;
	i = 0;
	while (argv[i])
	{
		if (atoi(argv[i]) > 2147483647)
			return (0);
		while (argv[i][x])
		{
			if (!ft_isdigit(argv[i][x]))
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	check_dupes()
{
	
	return (0);
}