/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:43:21 by sutku             #+#    #+#             */
/*   Updated: 2023/02/01 18:04:28 by sutku            ###   ########.fr       */
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
