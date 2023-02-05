/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:48 by sutku             #+#    #+#             */
/*   Updated: 2023/02/05 01:53:17 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_data	data;
	t_costs	cost;

	create_data(&data, &cost, len);
	find_median_arr(*stack_a, len, &data);
	push_c0(stack_a, stack_b, &data);
	while (data.size_a > 3)
		push_b(stack_a, stack_b, &data);
	if (is_sorted_a(*stack_a) != 0)
		three_number(stack_a, &data);
	check_contions(stack_a, stack_b, &data, &cost);
	last_sort(stack_a, &data);
}

int	check_errors(t_stack *stack, int count, char **argv, int len)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (long_atoi(argv[i]) < INT32_MIN || long_atoi(argv[i]) > INT32_MAX)
		{
			ft_printf("Error\n");
			return (-1);
		}
		if (is_integer(argv[i]) == -1)
			return (-1);
		if (is_duplicate_arr(argv + i) == -1)
			return (-1);
		if (is_duplicate(stack, long_atoi(argv[i]), len) == -1)
			return (-1);
	}
	return (0);
}

int	parsing(t_stack **stack_a, int argc, char **argv)
{
	char	**ptr;
	int		count;
	int		i;
	int		len;

	i = 1;
	len = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			ptr = ft_split(argv[i], 32);
			count = 0;
			while (ptr[count])
			{
				count++;
				len++;
			}
			if (check_errors(*stack_a, count, ptr, len) == -1)
				return (-1);
			create_linklist(stack_a, count, ptr);
			i++;
		}
	}
	return (len);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	len = parsing(&stack_a, argc, argv);
	if (len < 1)
		return (0);
	push_swap(&stack_a, &stack_b, len);
	delete_ll(&stack_a);
	return (0);
}
