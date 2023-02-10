/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:03 by sutku             #+#    #+#             */
/*   Updated: 2023/02/08 12:39:06 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stack **stack_a, t_data *data, int flag)
{
	t_stack	*last;

	last = *stack_a;
	if (data -> size_a > 1)
	{
		while (last -> next -> next != NULL)
			last = last -> next;
		last -> next -> next = *stack_a;
		*stack_a = last -> next;
		last -> next = NULL;
	}
	if (flag == 1)
		ft_printf("rra\n");
}

void	rev_rotate_b(t_stack **stack_b, t_data *data, int flag)
{
	t_stack	*last;

	last = *stack_b;
	if (data -> size_b > 1)
	{
		last = *stack_b;
		while (last -> next -> next != NULL)
			last = last -> next;
		last -> next -> next = *stack_b;
		*stack_b = last -> next;
		last -> next = NULL;
	}
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rev_rotate_ab(t_stack **stack_a, t_stack **stack_b,
		t_data *data, int flag)
{
	t_stack	*last;

	last = *stack_a;
	if (data -> size_a > 1 && data -> size_b > 1)
	{
		while (last -> next -> next != NULL)
			last = last -> next;
		last -> next -> next = *stack_a;
		(*stack_a) = last -> next;
		last -> next = NULL;
		last = *stack_b;
		while (last -> next -> next != NULL)
			last = last -> next;
		last -> next -> next = *stack_b;
		*stack_b = last -> next;
		last -> next = NULL;
	}
	if (flag == 1)
		ft_printf("rrr\n");
}
