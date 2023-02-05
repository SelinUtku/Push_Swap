/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:43:21 by sutku             #+#    #+#             */
/*   Updated: 2023/02/05 01:42:52 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_data_a(t_stack *stack, t_data *data)
{
	t_stack	*ptr;

	ptr = stack;
	data -> min_a = INT32_MAX;
	while (stack)
	{
		if (stack -> value < data -> min_a)
			data -> min_a = stack -> value;
		stack = stack -> next;
	}
	data -> max_a = INT32_MIN;
	stack = ptr;
	while (stack)
	{
		if (stack -> value >= data -> max_a)
			data -> max_a = stack -> value;
		stack = stack -> next;
	}
}

void	calculate_op(int min, t_costs *cost)
{
	cost -> shortest_op = min;
	cost -> rot_a = cost->op[0];
	cost -> rot_b = cost->op[2];
	cost -> rev_rot_a = cost->op[1];
	cost -> rev_rot_b = cost->op[3];
}

void	check_contions(t_stack **stack_a, t_stack **stack_b, t_data *data,
		t_costs *cost)
{
	while (*stack_b)
	{
		shortest_way(*stack_a, *stack_b, data, cost);
		if (cost -> shortest_op == find_max(cost -> rot_a, cost -> rot_b))
			c1(stack_a, stack_b, data, cost);
		else if (cost -> shortest_op == cost -> rot_a + cost -> rev_rot_b)
			c2(stack_a, stack_b, data, cost);
		else if (cost -> shortest_op == cost -> rev_rot_a + cost -> rot_b)
			c3(stack_a, stack_b, data, cost);
		else if (cost -> shortest_op == find_max(cost -> rev_rot_a,
				cost -> rev_rot_b))
			c4(stack_a, stack_b, data, cost);
		cost -> shortest_op = INT32_MAX;
		push_a(stack_a, stack_b, data);
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
