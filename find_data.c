/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:43:21 by sutku             #+#    #+#             */
/*   Updated: 2023/02/08 12:20:17 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_data_a(t_stack *stack, t_data *data)
{
	t_stack	*ptr;

	ptr = stack;
	data -> min_a = INT_MAX;
	while (stack)
	{
		if (stack -> value < data -> min_a)
			data -> min_a = stack -> value;
		stack = stack -> next;
	}
	data -> max_a = INT_MIN;
	stack = ptr;
	while (stack)
	{
		if (stack -> value >= data -> max_a)
			data -> max_a = stack -> value;
		stack = stack -> next;
	}
}

void	find_median(t_stack *stack, t_data *data, int *index)
{
	int	i;

	i = -1;
	while (++i < data -> size_a && stack)
	{
		if (index[i] == data -> size_a / 2)
		{
			data -> median = stack -> value;
			return ;
		}
		stack = stack -> next;
	}
}

void	find_median_arr(t_stack *stack, int len, t_data *data)
{
	t_stack	*first;
	int		*arr;
	int		i;

	i = 0;
	first = stack;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return ;
	while (stack)
	{
		arr[i] = stack -> value;
		stack = stack -> next;
		i++;
	}
	arr = find_index(len, arr);
	i = 0;
	find_median(first, data, arr);
	free(arr);
}
