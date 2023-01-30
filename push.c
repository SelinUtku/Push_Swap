/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:00 by sutku             #+#    #+#             */
/*   Updated: 2023/01/30 16:49:24 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (pb) Take the first element at the top of A and put it at the top of B.
void	push_b(t_stack **stack_A, t_stack **stack_B, t_data *data)
{
	t_stack *first_a;
	
	first_a = *stack_A;
	if (data -> A_size > 0)
	{
		if (data -> B_size == 0)
		{
			(*stack_A) = (*stack_A) -> next;
			first_a -> next = NULL;
			(*stack_B) = first_a;
			data -> operations++;
			data -> A_size--;
			data -> B_size++;
		}
		else
		{
			(*stack_A) = (*stack_A) -> next;
			first_a -> next = (*stack_B);
			*stack_B = first_a;
			data -> operations++;
			data -> A_size--;
			data -> B_size++;
		}
		ft_printf("pb\n");
	}
}
// (pa) Take the first element at the top of B and put it at the top of A.
void	push_a(t_stack **stack_A, t_stack **stack_B, t_data *data)
{
	t_stack *first_b;
	
	first_b = *stack_B;
	if (data -> B_size > 0)
	{
		if (data -> A_size == 0)
		{
			(*stack_B) = (*stack_B) -> next;
			first_b -> next = NULL;
			(*stack_A) = first_b;
			data -> operations++;
			data -> B_size--;
			data -> A_size++;
		}
		else
		{
			(*stack_B) = (*stack_B) -> next;
			first_b -> next = (*stack_A);
			*stack_A = first_b;
			data -> operations++;
			data -> B_size--;
			data -> A_size++;
		}
		ft_printf("pa\n");
	}
}