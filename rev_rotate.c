/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:03 by sutku             #+#    #+#             */
/*   Updated: 2023/01/15 18:28:12 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (rra) Shift down all elements of stack A by 1. The last element becomes the first one.
void	rev_rotate_a(s_stack **stack_A, s_data *data)
{
	s_stack *last;
	s_stack	*tmp;

	last = *stack_A;
	if (data -> A_size > 1)
	{
		while(last -> next != NULL)
		{
			tmp = last;
			last = last -> next;
		}
		last -> next = *stack_A;
		(*stack_A) = last;
		tmp -> next = NULL;
		data -> operations++;
	}
}
// (rrb) Shift down all elements of stack B by 1. The last element becomes the first one.
void	rev_rotate_b(s_stack **stack_B, s_data *data)
{
	s_stack *last;
	s_stack	*tmp;

	last = *stack_B;
	if (data -> B_size > 1)
	{
		last = *stack_B;
		while(last -> next != NULL)
		{
			tmp = last;
			last = last -> next;
		}
		last -> next =  *stack_B;
		(*stack_B) = last;
		tmp -> next = NULL;
		data -> operations++;
	}
}
// rra and rrb at the same time.
void	rev_rotate_ab(s_stack **stack_A, s_stack **stack_B, s_data *data)
{
	s_stack *last;
	s_stack	*tmp;

	last = *stack_A;
	if (data -> A_size > 1 && data -> B_size > 1)
	{
		// reverse rotate A
		while(last -> next != NULL)
		{
			tmp = last;
			last = last -> next;
		}
		last -> next =  *stack_A;
		(*stack_A) = last;
		tmp -> next = NULL;
		// reverse rotate B
		last = *stack_B;
		while(last -> next != NULL)
		{
			tmp = last;
			last = last -> next;
		}
		last -> next =  *stack_B;
		(*stack_B) = last;
		tmp -> next = NULL;
		data -> operations++;
	}
}