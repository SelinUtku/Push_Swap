/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:19:02 by sutku             #+#    #+#             */
/*   Updated: 2023/02/01 12:42:08 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack *stack, t_data *data)
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

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	find_median(t_stack *stack, t_data *data, int *index)
{
	int	i;

	i = -1;
	while (++i < data -> size_a)
	{
		if (index[i] == data -> size_a / 2)
		{
			data -> median = stack -> value;
			return ;
		}
		stack = stack -> next;
	}
}

void	last_sort(t_stack **stack, t_data *data)
{
	while (min_index(*stack, data) != 0)
	{
		if (min_index(*stack, data) < data -> size_a / 2.0)
			rotate_a(stack, data);
		else
			rev_rotate_a(stack, data);
	}
}
