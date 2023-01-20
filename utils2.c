/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:13:02 by sutku             #+#    #+#             */
/*   Updated: 2023/01/20 19:57:56 by sutku            ###   ########.fr       */
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

int	is_duplicate_arr(char **argv, int flag)
{
	int	i;
	int	j;
	
	i = 0;
	if (flag == -1)
		i = -1;
	while(argv[++i]!= NULL)
	{
		j = i + 1;
		while(argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
				return (-1);
		}
	}
	return (0);
}

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}