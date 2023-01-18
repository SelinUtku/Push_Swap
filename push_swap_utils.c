/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:44:17 by sutku             #+#    #+#             */
/*   Updated: 2023/01/18 23:26:56 by sutku            ###   ########.fr       */
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
// !!! NORMINETTE 
void	create_linklist(s_stack **stack,int argc, char **argv, s_data *data)
{
	s_stack	*first;
	s_stack	*last;
	int	i;
	long int if_not_int;
	
	i = 0;
	if_not_int = ft_atoi(argv[0], &data);
	if (data -> flag == 0)
	{
		printf("Error : Number is not integer\n");
		delete_ll(stack);
		return;
	}
	first = *stack;
	first -> value = ft_atoi(argv[0], &data);
	first -> next = NULL;
	(*stack) = first;
	last = first;
	while (++i < argc - 1)
	{
		if_not_int = ft_atoi(argv[i], &data);
		if (data -> flag == 0)
		{
			printf("Error : Number is not integer\n");
			delete_ll(stack);
			return ;
		}
		s_stack	*tmp;
		tmp = malloc (sizeof(s_stack));
		tmp -> value = ft_atoi(argv[i],&data);
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
	data -> flag = 1;
}

