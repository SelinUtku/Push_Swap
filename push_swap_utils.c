/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:44:17 by sutku             #+#    #+#             */
/*   Updated: 2023/01/30 02:51:34 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	delete_ll(s_stack **stack)
{
	s_stack *first;

	while((*stack))
	{
		first = *stack;
		*stack = (*stack) -> next;
		free(first);
	}	
}

void	create_linklist(s_stack **stack,int argc, char **argv)
{
	s_stack	*last;
	int	i;
	
	*stack = (s_stack *)malloc(sizeof(s_stack));
	i = 0;
	(*stack) -> value = ft_atoi(argv[0]);
	(*stack) -> next = NULL;
	last = (*stack);
	while (++i < argc - 1)
	{
		//malloc protection !
		s_stack	*tmp;
		tmp = malloc (sizeof(s_stack));
		tmp -> value = ft_atoi(argv[i]);
		tmp -> next = NULL;
		last -> next = tmp;
		last = tmp;
	}
}

void	create_data(s_data *data, t_costs *cost, int argc)
{
	data -> A_size = argc - 1;
	data -> B_size = 0;
	data -> operations = 0;
	data -> min_A = INT32_MAX;
	data -> max_A = INT32_MIN;
	data -> min_B = INT32_MAX;
	data -> max_B = INT32_MIN;
	data -> median = 0;
	cost -> shortest_op = INT32_MAX;
	cost ->	rot_a = -1;
	cost -> rot_b = -1;
	cost -> rev_rot_a = -1;
	cost -> rev_rot_b = -1;
	
}

void	three_number(s_stack **stack, s_data *data)
{
	int a;

	while (*stack && min_index(*stack, data) != 0 && is_sorted_a(*stack) == -1)
	{
		a = min_index(*stack, data);
		if (a < (data->A_size / 2.0))
			rotate_a(stack, data);
		else
			rev_rotate_a(stack, data);
	}
	if (*stack && is_sorted_a(*stack) == -1)
	{
		swap_a(stack, data);
		rotate_a(stack, data);
	}
}

void	shortest_way(s_stack *stack_a, s_stack *stack_b, s_data *data, t_costs *cost)
{
	int	*op;
	int	num;
	int i;
	int	min;

	i = 0;
	min = INT32_MAX;
	op = (int *)malloc(sizeof(int) * 4);
	while (i < data -> B_size)
	{
		num = find_index_inA(&stack_a, &stack_b);
		op[0] = num;//ra
		op[1] = data -> A_size - num;//rra
		op[2] = i;//rb
		if (data -> B_size == 1)//rrb
			op[3] = 0;
		else
			op[3] = data -> B_size - i;
		// 							(ra+rb) 		(ra+rrb) 	(rra+rb) 			(rra+rrb)
		min = find_min(find_min(find_max(op[0],op[2]), (op[0] + op[3])), find_min((op[1] + op[2]), find_max(op[1], op[3])));
		if (min < cost -> shortest_op)
		{
			cost -> shortest_op = min;
			cost -> rot_a = op[0];
			cost -> rot_b = op[2];
			cost -> rev_rot_a = op[1];
			cost -> rev_rot_b = op[3];
		}
		stack_b = stack_b -> next;
		i++;
	}
}
