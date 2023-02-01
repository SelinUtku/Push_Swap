/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:00 by sutku             #+#    #+#             */
/*   Updated: 2023/02/01 12:37:58 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*first_a;

	first_a = *stack_a;
	if (data -> size_a > 0)
	{
		if (data -> size_b == 0)
		{
			(*stack_a) = (*stack_a)-> next;
			first_a -> next = NULL;
			(*stack_b) = first_a;
			data -> operations++;
			data -> size_a--;
			data -> size_b++;
		}
		else
		{
			(*stack_a) = (*stack_a)-> next;
			first_a -> next = (*stack_b);
			*stack_b = first_a;
			data -> operations++;
			data -> size_a--;
			data -> size_b++;
		}
		ft_printf("pb\n");
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*first_b;

	first_b = *stack_b;
	if (data -> size_b > 0)
	{
		if (data -> size_a == 0)
		{
			(*stack_b) = (*stack_b)-> next;
			first_b -> next = NULL;
			(*stack_a) = first_b;
			data -> operations++;
			data -> size_b--;
			data -> size_a++;
		}
		else
		{
			(*stack_b) = (*stack_b)-> next;
			first_b -> next = (*stack_a);
			*stack_a = first_b;
			data -> operations++;
			data -> size_b--;
			data -> size_a++;
		}
		ft_printf("pa\n");
	}
}
