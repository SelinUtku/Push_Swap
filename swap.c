/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:55:23 by sutku             #+#    #+#             */
/*   Updated: 2023/01/30 16:49:25 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (sa) Swap the first 2 elements at the top of stack A.
void	swap_a(t_stack **stack_A, t_data *data)
{
	t_stack *first;
	t_stack *second;
	int	value1;
	int value2;
	
	if (data -> A_size > 1)
	{
		first = *stack_A;
		second = (*stack_A) -> next;

		value1 = first -> value;
		value2 = second -> value;
		first -> value = value2;
		second -> value = value1;
		data -> operations++;
	}
	ft_printf("sa\n");
}
// (sb) Swap the first 2 elements at the top of stack B.
void	swap_b(t_stack **stack_B, t_data *data)
{
	t_stack *first;
	t_stack *second;
	int	value1;
	int value2;
	if (data -> B_size > 1)
	{
		first = *stack_B;
		second = (*stack_B) -> next;
		
		value1 = first -> value;
		value2 = second -> value;
		first -> value = value2;
		second -> value = value1;
		data -> operations++;
	}
}
// (ss) sa and sb at the same time.
void	swap_ab(t_stack **stack_A, t_stack **stack_B, t_data *data)
{
	t_stack *first;
	t_stack *second;
	int	value1;
	int value2;

// Swap first 2 elements of stack_A
	if (data -> A_size > 1 && data -> B_size > 1)
	{
		first = *stack_A;
		second = (*stack_A) -> next;
		
		value1 = first -> value;
		value2 = second -> value;
		first -> value = value2;
		second -> value = value1;

// Swap first 2 elements of stack_B
		first = *stack_B;
		second = (*stack_B) -> next;
		
		value1 = first -> value;
		value2 = second -> value;
		first -> value = value2;
		second -> value = value1;
		data -> operations++;
	}
}