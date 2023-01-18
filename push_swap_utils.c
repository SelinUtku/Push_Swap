/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:44:17 by sutku             #+#    #+#             */
/*   Updated: 2023/01/15 21:22:18 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_linklist(s_stack **stack,int argc, char **argv)
{
	s_stack	*first;
	s_stack	*last;
	int	i;
	
	i = 0;
	first = *stack;
	first->value = ft_atoi(argv[1]);
	first->next = NULL;
	(*stack) = first;
	last = first;
	while (++i < argc - 1)
	{
		s_stack	*tmp;
		tmp = malloc (sizeof(s_stack));
		tmp->value = ft_atoi(argv[i + 1]);
		tmp->next = NULL;
		last->next = tmp;
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
}

