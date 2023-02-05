/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:03:18 by sutku             #+#    #+#             */
/*   Updated: 2023/02/05 02:03:50 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_number(t_stack **stack, t_data *data)
{
	int	a;

	a = min_index(*stack, data);
	while (a)
	{
		if (a < (data -> size_a / 2.0))
			rotate_a(stack, data);
		else
			rev_rotate_a(stack, data);
		a = min_index(*stack, data);
	}
	if (*stack && is_sorted_a(*stack) == -1)
	{
		swap_a(stack, data);
		rotate_a(stack, data);
	}
}

void	shortest_way(t_stack *stack_a, t_stack *stack_b,
t_data *data, t_costs *cost)
{
	int	num;
	int	i;
	int	min;

	i = 0;
	min = INT32_MAX;
	while (i < data -> size_b)
	{
		num = find_index_in_a(stack_a, stack_b, data);
		cost->op[0] = num;
		cost->op[1] = data -> size_a - num;
		cost->op[2] = i;
		if (data -> size_b == 1)
			cost->op[3] = 0;
		else
			cost->op[3] = data -> size_b - i;
		min = find_min(find_min(find_max(cost->op[0], cost->op[2]),
					(cost->op[0] + cost->op[3])),
				find_min((cost->op[1] + cost->op[2]),
					find_max(cost->op[1], cost->op[3])));
		if (min < cost -> shortest_op)
			calculate_op(min, cost);
		stack_b = stack_b -> next;
		i++;
	}
}
