/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:48 by sutku             #+#    #+#             */
/*   Updated: 2023/02/01 18:01:41 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, t_data *data,
		t_costs *cost)
{
	push_c0(stack_a, stack_b, data);
	while (data -> size_a > 3)
		push_b(stack_a, stack_b, data);
	if (is_sorted_a(*stack_a) != 0)
		three_number(stack_a, data);
	while (*stack_b)
	{
		shortest_way(*stack_a, *stack_b, data, cost);
		if (cost -> shortest_op == find_max(cost -> rot_a, cost -> rot_b))
			c1(stack_a, stack_b, data, cost);
		else if (cost -> shortest_op == cost -> rot_a + cost -> rev_rot_b)
			c2(stack_a, stack_b, data, cost);
		else if (cost -> shortest_op == cost -> rev_rot_a + cost -> rot_b)
			c3(stack_a, stack_b, data, cost);
		else if (cost -> shortest_op == find_max(cost -> rev_rot_a,
				cost -> rev_rot_b))
			c4(stack_a, stack_b, data, cost);
		cost -> shortest_op = INT32_MAX;
		push_a(stack_a, stack_b, data);
	}
	last_sort(stack_a, data);
}

int	check_errors(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
	{
		if (long_atoi(argv[i]) < INT32_MIN || long_atoi(argv[i]) > INT32_MAX)
		{
			ft_printf("Error\n");
			return (-1);
		}
		if (is_integer(argv[i]) == -1)
		{
			ft_printf("Error\n");
			return (-1);
		}
		if (is_duplicate_arr(argv + i) == -1)
		{
			ft_printf("Error\n");
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;
	t_costs	cost;
	char	**ptr;
	int		count;
	int		*index;

	stack_a = NULL;
	stack_b = NULL;
	count = 0;
	if (argc == 2)
	{
		ptr = ft_split(argv[1], 32);
		while (ptr[count])
			count++;
		if(check_errors(count + 1, ptr) == -1)
			return (0);
		index = find_index(count + 1, ptr);
		create_data(&data, &cost, count + 1);
		create_linklist(&stack_a, count + 1, ptr);
	}
	else if (argc > 1)
	{
		if (check_errors(argc, argv + 1) == -1)
			return (0);
		index = find_index(argc, argv + 1);
		create_data(&data, &cost,argc);
		create_linklist(&stack_a, argc, argv + 1);
	}
	find_median(stack_a, &data, index);
	push_swap(&stack_a, &stack_b, &data, &cost);
	free(index);
	delete_ll(&stack_a);
	delete_ll(&stack_b);
	return (0);
}
