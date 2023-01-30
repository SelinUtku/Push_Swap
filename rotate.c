/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:06 by sutku             #+#    #+#             */
/*   Updated: 2023/01/30 16:49:25 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// (ra) Shift up all elements of stack A by 1. The first element becomes the last one.
void	rotate_a(t_stack **stack_A, t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

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
	ft_printf("ra\n");
}
// (rb) Shift up all elements of stack B by 1. The first element becomes the last one.
void	rotate_b(t_stack **stack_B, t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

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
	ft_printf("rb\n");
}
// (rr) ra and rb at the same time.
void	rotate_ab(t_stack **stack_A, t_stack **stack_B, t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;
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
	ft_printf("rr\n");
}