/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:19:02 by sutku             #+#    #+#             */
/*   Updated: 2023/01/30 03:10:29 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(s_stack *stack, s_data *data)
{
	int index;

	index = 0;
	while (stack)
	{
		if (stack -> value == data -> min_A)
			return(index);
		index++;
		stack = stack -> next;
	}
	return(-1);
}

int find_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_min(int a, int b)
{
	if (a < b)
		return(a);
	return(b);
}

void last_sort(s_stack **stack, s_data *data)
{
	s_stack *iter;
	int	count;

	iter = *stack;
	count = 0;
	while (iter -> value != data -> min_A)
	{
		iter = iter -> next;
		count++;
	}
	
	if (count < data -> A_size / 2.0)
	{
		while (is_sorted_a(*stack) == -1)
			rotate_a(stack, data);
	}
	else
	{
		while(is_sorted_a(*stack) == -1)
			rev_rotate_a(stack, data);
	}
}