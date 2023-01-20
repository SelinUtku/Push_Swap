/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:13:02 by sutku             #+#    #+#             */
/*   Updated: 2023/01/18 23:13:44 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_sorted(s_stack *stack_A)
{
	s_stack	*iter;

	iter = stack_A -> next;
	while(iter)
	{
		if (iter -> value < stack_A -> value)
			return (0);
		iter = iter -> next;
		stack_A = stack_A -> next;
	}
	return (1);
}

void	is_duplicate(s_stack *stack)
{
	s_stack *iter;
	
	while (stack)
	{
		iter = stack -> next;
		while (iter)
		{
			if (iter -> value == stack -> value)
			{
				printf("Error : Duplicate elements\n");
				break;
			}
			iter = iter -> next;
		}
		stack = stack -> next;
	}
}

// int	is_duplicate_arr(char **argv)
// {
// 	char *ptr;
// 	int i;
// 	int	j;


// 	return (0);
// }