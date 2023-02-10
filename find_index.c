/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:45:49 by sutku             #+#    #+#             */
/*   Updated: 2023/02/08 12:20:22 by sutku            ###   ########.fr       */
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
		return (index_of_min(stack_a, data));
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

void	put_zero(int **new, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		(*new)[i] = 0;
		i++;
	}
}

void	*find_index(int argc, int *arr)
{
	int	*new;
	int	i;
	int	j;
	int	small;

	new = malloc(sizeof(int) * (argc));
	if (!new)
		return (NULL);
	put_zero(&new, argc);
	i = -1;
	while (++i < argc)
	{
		j = -1;
		small = 0;
		while (++j < i)
		{
			if (arr[j] < arr[i])
				small++;
			else if (arr[j] > arr[i])
				new[j]++;
		}
		new[i] = small;
	}
	free(arr);
	return (new);
}

int	index_of_min(t_stack *stack, t_data *data)
{
	int	index;

	find_data_a(stack, data);
	index = 0;
	while (stack)
	{
		if (stack -> value == data -> min_a)
			return (index);
		index++;
		stack = stack -> next;
	}
	return (-1);
}
