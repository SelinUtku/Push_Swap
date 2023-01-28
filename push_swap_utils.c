/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:44:17 by sutku             #+#    #+#             */
/*   Updated: 2023/01/27 18:17:52 by sutku            ###   ########.fr       */
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

void	create_data(s_data *data, int argc)
{
	data -> A_size = argc - 1;
	data -> B_size = 0;
	data -> operations = 0;
	data -> min_A = INT32_MAX;
	data -> max_A = INT32_MIN;
	data -> min_B = INT32_MAX;
	data -> max_B = INT32_MIN;
	data -> median = 0;
}

void	three_number(s_stack **stack, s_data *data)
{
	int a;

	while (*stack && min_index(*stack, data) != 0 && is_sorted_a(*stack) == -1)
	{
		a = min_index(*stack, data);
		if (a <= (data->A_size / 2))
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
