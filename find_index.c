/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:45:49 by sutku             #+#    #+#             */
/*   Updated: 2023/01/26 18:32:10 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*find_index(int argc, char **argv)
{
	int	*new;
	int	i;
	int	j;
	int	small;

	i = 0;
	new = malloc(sizeof(int) * (argc - 1));
	if (!new)
		return (NULL);
	while (i < argc - 1)
		new[i++] = 0;
	i = -1;
	while (argv[++i] != NULL)
	{
		j = -1;
		small = 0;
		while (++j < i)
		{
			if (long_atoi(argv[j]) < long_atoi(argv[i]))
				small++;
			else if (long_atoi(argv[j]) > long_atoi(argv[i]))
				new[j]++;
		}
		new[i] = small;
	}
	return (new);
}

int	find_index_inA(s_stack  **stack_a, s_stack **stack_b)
{
	s_stack *a;
	s_stack	*b;
	int	index;

	a = *stack_a;
	b = *stack_b;
	index = 0;
	if (b -> value > a -> value && a -> next == NULL)
		return (1);
	while (a -> next != NULL)
	{
		if (b -> value > a -> value && b -> value < a -> next -> value)
			return (index + 1);
		index++;
		a = a -> next;
	}
	return(0);
}
