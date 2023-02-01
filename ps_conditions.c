/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:55:52 by sutku             #+#    #+#             */
/*   Updated: 2023/02/01 13:16:25 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_c0(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int	i;

	find_data_a(*stack_a, data);
	i = data -> size_a + 1;
	if (data -> size_a >= 50)
	{
		while (--i > 0)
		{
			if ((*stack_a)-> value > data -> median)
				push_b(stack_a, stack_b, data);
			else
				rotate_a(stack_a, data);
		}
	}
}

void	c1(t_stack **stack_a, t_stack **stack_b, t_data *data, t_costs *cost)
{
	while (cost -> rot_a > 0 && cost -> rot_b > 0)
	{
		rotate_ab(stack_a, stack_b, data);
		cost -> rot_a--;
		cost -> rot_b--;
	}
	while (cost -> rot_a > 0)
	{
		rotate_a(stack_a, data);
		cost -> rot_a--;
	}
	while (cost -> rot_b > 0)
	{
		rotate_b(stack_b, data);
		cost -> rot_b--;
	}
}

void	c2(t_stack **stack_a, t_stack **stack_b, t_data *data, t_costs *cost)
{
	while (cost -> rot_a > 0)
	{
		rotate_a(stack_a, data);
		cost -> rot_a--;
	}
	while (cost -> rev_rot_b > 0)
	{
		rev_rotate_b(stack_b, data);
		cost -> rev_rot_b--;
	}
}

void	c3(t_stack **stack_a, t_stack **stack_b, t_data *data, t_costs *cost)
{
	while (cost -> rev_rot_a > 0)
	{
		rev_rotate_a(stack_a, data);
		cost -> rev_rot_a--;
	}
	while (cost -> rot_b > 0)
	{
		rotate_b(stack_b, data);
		cost -> rot_b--;
	}
}

void	c4(t_stack **stack_a, t_stack **stack_b, t_data *data, t_costs *cost)
{
	while (cost -> rev_rot_a > 0 && cost -> rev_rot_b > 0)
	{
		rev_rotate_ab(stack_a, stack_b, data);
		cost -> rev_rot_a--;
		cost -> rev_rot_b--;
	}
	while (cost -> rev_rot_a > 0)
	{
		rev_rotate_a(stack_a, data);
		cost -> rev_rot_a--;
	}
	while (cost -> rev_rot_b > 0)
	{
		rev_rotate_b(stack_b, data);
		cost -> rev_rot_b--;
	}
}
