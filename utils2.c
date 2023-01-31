/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:19:02 by sutku             #+#    #+#             */
/*   Updated: 2023/01/31 18:35:51 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack *stack, t_data *data)
{
	int index;

	find_data_a(stack, data);
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

void last_sort(t_stack **stack, t_data *data)
{
	while (min_index(*stack, data) != 0)
	{
		if (min_index(*stack,data) < data -> A_size / 2.0)
			rotate_a(stack, data);
		else
			rev_rotate_a(stack, data);
	}
}