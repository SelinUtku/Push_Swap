/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:45:49 by sutku             #+#    #+#             */
/*   Updated: 2023/01/31 19:04:21 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	find_index_inA(t_stack  *stack_a, t_stack *stack_b, t_data *data)
{
	int	index;
	
	index = 0;
	find_data_a(stack_a, data);
	if (stack_b -> value > stack_a -> value && stack_a->next == NULL)
		return (1);
	if (stack_b -> value < data -> min_A || stack_b -> value > data -> max_A)
		return(min_index(stack_a, data));
	while (stack_a -> next != NULL)
	{
		if (stack_b -> value > stack_a -> value && stack_b -> value < stack_a -> next -> value)
			return (index + 1);
		index++;
		stack_a = stack_a -> next;
	}
	return(0);
}
