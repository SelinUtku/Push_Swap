/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:13:02 by sutku             #+#    #+#             */
/*   Updated: 2023/01/27 16:01:37 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(s_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> value > stack -> next -> value)
			return (-1);
		stack = stack -> next;
	}
	return (0);
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