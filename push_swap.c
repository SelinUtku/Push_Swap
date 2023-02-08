/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:48 by sutku             #+#    #+#             */
/*   Updated: 2023/02/08 10:09:25 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_data	data;
	t_costs	cost;

	if (is_sorted_a(*stack_a) == 0)
		return ;
	create_data(&data, &cost, len);
	find_median_arr(*stack_a, len, &data);
	push_c0(stack_a, stack_b, &data);
	while (data.size_a > 3)
		push_b(stack_a, stack_b, &data, 1);
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
		if (long_atoi(argv[i]) < INT_MIN || long_atoi(argv[i]) > INT_MAX)
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

void	memory_free_ps(char **ptr)
{
	unsigned int	j;

	j = 0;
	while (ptr[j] != NULL)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
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
			count = -1;
			while (ptr[++count])
				len++;
			if (check_errors(*stack_a, count, ptr, len) == -1)
				{memory_free_ps(ptr);
				return (-1);}
			create_linklist(stack_a, count, ptr);
			memory_free_ps(ptr);
			i++;
		}
	}
	return (len);
}
