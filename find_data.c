/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:43:21 by sutku             #+#    #+#             */
/*   Updated: 2023/01/27 12:22:06 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_data_a(s_stack *stack, s_data *data)
{
	s_stack *ptr;

	ptr = stack;
	// Find min_a
	while (stack)
	{
		if (stack -> value < data -> min_A)
			data -> min_A = stack -> value;
		stack = stack -> next;
	}
	// find max_a
	stack = ptr;
	while (stack)
	{
		if (stack -> value >= data -> max_A)
			data -> max_A = stack -> value;
		stack = stack -> next;
	}
}

// void	find_min_b(s_stack *stack, s_data *data)
// {
// 	while (stack)
// 	{
// 		if (stack -> value <= data -> min_B)
// 			data -> min_B = stack -> value;
// 		stack = stack -> next;
// 	}
// 	printf("min_b = %d ", data -> min_B);
// }

// void	find_max_b(s_stack *stack, s_data *data)
// {
// 	while (stack)
// 	{
// 		if (stack -> value >= data -> max_B)
// 			data -> max_B = stack -> value;
// 		stack = stack -> next;
// 	}
// 	printf("max_a = %d ", data -> max_B);
// }

void	find_median(s_stack *stack, s_data *data, int *index)
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