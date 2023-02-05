/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:45:49 by sutku             #+#    #+#             */
/*   Updated: 2023/02/05 01:45:12 by sutku            ###   ########.fr       */
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

void	*find_index(int argc, int *argv)
{
	int	*new;
	int	i;
	int	j;
	int	small;

	i = 0;
	new = malloc(sizeof(int) * (argc));
	if (!new)
		return (NULL);
	while (i < argc)
		new[i++] = 0;
	i = -1;
	while (++i < argc)
	{
		j = -1;
		small = 0;
		while (++j < i)
		{
			if (argv[j] < argv[i])
				small++;
			else if (argv[j] > argv[i])
				new[j]++;
		}
		new[i] = small;
	}
	return (new);
}
