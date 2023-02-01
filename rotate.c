/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:06 by sutku             #+#    #+#             */
/*   Updated: 2023/02/01 12:37:59 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a, t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack_a;
	last = *stack_a;
	if (data -> size_a > 1)
	{
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		*stack_a = (*stack_a)-> next;
		last -> next = NULL;
		tmp -> next = last;
		data -> operations++;
	}
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b, t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack_b;
	last = *stack_b;
	if (data -> size_b > 1)
	{
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		*stack_b = (*stack_b)-> next;
		last -> next = NULL;
		tmp -> next = last;
		data -> operations++;
	}
	ft_printf("rb\n");
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack_a;
	last = *stack_a;
	if (data -> size_a > 1 && data -> size_b > 1)
	{
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		*stack_a = (*stack_a)-> next;
		last -> next = NULL;
		tmp -> next = last;
		tmp = *stack_b;
		last = *stack_b;
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		*stack_b = (*stack_b)-> next;
		last -> next = NULL;
		tmp -> next = last;
		data -> operations++;
	}
	ft_printf("rr\n");
}
