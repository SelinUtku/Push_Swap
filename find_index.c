/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:45:49 by sutku             #+#    #+#             */
/*   Updated: 2023/02/01 12:42:35 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_in_a(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	int	index;

	index = 0;
	find_data_a(stack_a, data);
	if (stack_b -> value > stack_a -> value && stack_a->next == NULL)
		return (1);
	if (stack_b -> value < data -> min_a || stack_b -> value > data -> max_a)
		return (min_index(stack_a, data));
	while (stack_a -> next != NULL)
	{
		if (stack_b -> value > stack_a -> value && stack_b -> value
			< stack_a -> next -> value)
			return (index + 1);
		index++;
		stack_a = stack_a -> next;
	}
	return (0);
}

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
