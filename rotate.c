/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:06 by sutku             #+#    #+#             */
/*   Updated: 2023/01/15 18:04:26 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// (ra) Shift up all elements of stack A by 1. The first element becomes the last one.
void	rotate_a(s_stack **stack_A, s_data *data)
{
	s_stack	*tmp;
	s_stack	*last;

	tmp = *stack_A;
	last = *stack_A;
	if (data -> A_size > 1)
	{
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		*stack_A = (*stack_A) -> next;
		last -> next = NULL;
		tmp -> next = last;
		data -> operations++;
	}
}
// (rb) Shift up all elements of stack B by 1. The first element becomes the last one.
void	rotate_b(s_stack **stack_B, s_data *data)
{
	s_stack	*tmp;
	s_stack	*last;

	tmp = *stack_B;
	last = *stack_B;
	if (data -> B_size > 1)
	{
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		*stack_B = (*stack_B) -> next;
		last -> next = NULL;
		tmp -> next = last;
		data -> operations++;
	}
}
// (rr) ra and rb at the same time.
void	rotate_ab(s_stack **stack_A, s_stack **stack_B, s_data *data)
{
	s_stack	*tmp;
	s_stack	*last;
// rotate a
	tmp = *stack_A;
	last = *stack_A;
	if (data -> A_size > 1 && data -> B_size > 1)
	{
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		*stack_A = (*stack_A) -> next;
		last -> next = NULL;
		tmp -> next = last;
// rotate b
		tmp = *stack_B;
		last = *stack_B;
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		*stack_B = (*stack_B) -> next;
		last -> next = NULL;
		tmp -> next = last;
		data -> operations++;
	}
}