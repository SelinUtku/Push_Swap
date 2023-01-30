/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:03 by sutku             #+#    #+#             */
/*   Updated: 2023/01/30 16:49:24 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (rra) Shift down all elements of stack A by 1. The last element becomes the first one.
void	rev_rotate_a(t_stack **stack_A, t_data *data)
{
	t_stack *last;
	t_stack	*tmp;

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
	ft_printf("rra\n");
}
// (rrb) Shift down all elements of stack B by 1. The last element becomes the first one.
void	rev_rotate_b(t_stack **stack_B, t_data *data)
{
	t_stack *last;
	t_stack	*tmp;

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
	ft_printf("rrb\n");
}
// rra and rrb at the same time.
void	rev_rotate_ab(t_stack **stack_A, t_stack **stack_B, t_data *data)
{
	t_stack *last;
	t_stack	*tmp;

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
	ft_printf("rrr\n");
}