/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:03:18 by sutku             #+#    #+#             */
/*   Updated: 2023/02/06 13:38:09 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_number(t_stack **stack, t_data *data)
{
	int	a;

	a = index_of_min(*stack, data);
	while (a)
	{
		if (a < (data -> size_a / 2.0))
			rotate_a(stack, data, 1);
		else
			rev_rotate_a(stack, data, 1);
		a = index_of_min(*stack, data);
	}
	if (*stack && is_sorted_a(*stack) == -1)
	{
		swap_a(stack, data, 1);
		rotate_a(stack, data, 1);
	}
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
		push_a(stack_a, stack_b, data, 1);
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

void	last_sort(t_stack **stack, t_data *data)
{
	while (index_of_min(*stack, data) != 0)
	{
		if (index_of_min(*stack, data) < data -> size_a / 2.0)
			rotate_a(stack, data, 1);
		else
			rev_rotate_a(stack, data, 1);
	}
}
