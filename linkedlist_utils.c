/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:44:17 by sutku             #+#    #+#             */
/*   Updated: 2023/02/08 09:32:29 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_ll(t_stack **stack)
{
	t_stack	*first;

	while ((*stack))
	{
		first = *stack;
		*stack = (*stack)-> next;
		free (first);
	}
}

void	add_node_back(t_stack **stack, int i, int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*last;

	last = (*stack);
	while (last -> next != NULL)
		last = last -> next;
	while (++i < argc)
	{
		tmp = malloc (sizeof(t_stack));
		if (!tmp)
		{
			delete_ll(stack);
			return ;
		}
		tmp -> value = ft_atoi(argv[i]);
		tmp -> next = NULL;
		last -> next = tmp;
		last = tmp;
	}
}

void	create_linklist(t_stack **stack, int argc, char **argv)
{
	int		i;

	i = -1;
	if (*stack == NULL)
	{
		i++;
		*stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*stack)
			return ;
		(*stack)-> value = ft_atoi(argv[i]);
		(*stack)-> next = NULL;
	}
	add_node_back(stack, i, argc, argv);
}

void	create_data(t_data *data, t_costs *cost, int argc)
{
	data -> size_a = argc;
	data -> size_b = 0;
	data -> operations = 0;
	data -> min_a = INT_MAX;
	data -> max_a = INT_MIN;
	data -> median = 0;
	cost -> shortest_op = INT_MAX;
	cost -> rot_a = -1;
	cost -> rot_b = -1;
	cost -> rev_rot_a = -1;
	cost -> rev_rot_b = -1;
}
