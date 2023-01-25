/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:13:02 by sutku             #+#    #+#             */
/*   Updated: 2023/01/24 18:06:10 by sutku            ###   ########.fr       */
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

int	is_duplicate_arr(char **argv)
{
	int	i;
	int num;

	i = 1;
	num = long_atoi(argv[0]);
	while (argv[i] != NULL)
	{
		if (num == long_atoi(argv[i++]))
			return (-1);
	}
	return (0);
}

int	is_integer(char *str)
{
	int	i;
	int	control;

	i = 0;
	control = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
		control = 1;
	}
	if (control == 0)
		return(-1);
	return (0);
}