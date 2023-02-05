/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:13:02 by sutku             #+#    #+#             */
/*   Updated: 2023/02/05 01:57:16 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> value > stack -> next -> value)
			return (-1);
		stack = stack -> next;
	}
	return (0);
}

int	is_duplicate(t_stack *stack, int a, int len)
{
	if (len > 1)
	{
		while (stack)
		{
			if (stack -> value == a)
			{
				ft_printf("Error\n");
				return (-1);
			}
			stack = stack -> next;
		}
	}
	return (0);
}

int	is_duplicate_arr(char **argv)
{
	int	i;
	int	num;

	i = 1;
	num = long_atoi(argv[0]);
	while (argv[i] != NULL)
	{
		if (num == long_atoi(argv[i++]))
		{
			ft_printf("Error\n");
			return (-1);
		}
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
		{
			ft_printf("Error\n");
			return (-1);
		}
		control = 1;
		i++;
	}
	if (control == 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	return (0);
}
