/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:43:21 by sutku             #+#    #+#             */
/*   Updated: 2023/01/31 18:44:54 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_data_a(t_stack *stack, t_data *data)
{
	t_stack *ptr;

	ptr = stack;
	data -> min_A = INT32_MAX;
	// Find min_a
	while (stack)
	{
		if (stack -> value < data -> min_A)
			data -> min_A = stack -> value;
		stack = stack -> next;
	}
	// find max_a
	data -> max_A = INT32_MIN;
	stack = ptr;
	while (stack)
	{
		if (stack -> value >= data -> max_A)
			data -> max_A = stack -> value;
		stack = stack -> next;
	}
}

void	find_median(t_stack *stack, t_data *data, int *index)
{
	int	i;

	i = -1;
	while (++i < data -> A_size)
	{
		if (index[i] == data -> A_size / 2)
		{
			data -> median = stack -> value;
			return;
		}
		stack = stack -> next;
	}
}