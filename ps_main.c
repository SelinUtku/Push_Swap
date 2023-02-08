/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:33:22 by sutku             #+#    #+#             */
/*   Updated: 2023/02/08 10:22:32 by Cutku            ###   ########.fr       */
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
		return (0);
	}
	push_swap(&stack_a, &stack_b, len);
	delete_ll(&stack_a);
	return (0);
}
