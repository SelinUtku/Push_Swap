/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:33:22 by sutku             #+#    #+#             */
/*   Updated: 2023/02/09 18:05:24 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	len = parsing(&stack_a, argc, argv);
	if (len < 1)
	{
		delete_ll(&stack_a);
		return (-1);
	}
	push_swap(&stack_a, &stack_b, len);
	delete_ll(&stack_a);
	delete_ll(&stack_b);
	return (0);
}
