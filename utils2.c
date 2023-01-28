/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:19:02 by sutku             #+#    #+#             */
/*   Updated: 2023/01/27 17:59:06 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(s_stack *stack, s_data *data)
{
	int index;

	index = 0;
	while (stack)
	{
		if (stack -> value == data -> min_A)
			return(index);
		index++;
		stack = stack -> next;
	}
	return(-1);
}