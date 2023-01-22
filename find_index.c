/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:45:49 by sutku             #+#    #+#             */
/*   Updated: 2023/01/23 00:03:48 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_index(int argc, char **argv)
{
	int	*new;
	int	i;
	int	j;
	int	small;
// for norminette fix the code
// fix the code according to if argc = 2 
	i = 0;
	new = malloc(sizeof(int) * argc - 1);
	if (!new)
		return ;
	while (i < argc - 1)
		new[i++] = 0;
	i = 0;
	while (argv[++i] != NULL && i < argc - 1)
	{
		j = 0;
		small = 0;
		while (j < i)
		{
			if (ft_atoi(argv[j + 1]) < ft_atoi(argv[i + 1]))
				small++;
			else if (ft_atoi(argv[j + 1]) > ft_atoi(argv[i + 1]))
				new[j]++;
			j++;
		}
		new[i] = small;
	}
i = 0;
while (i < argc - 1)
	printf("%d ", new[i++]);
}

