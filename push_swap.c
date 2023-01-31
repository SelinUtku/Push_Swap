/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:48 by sutku             #+#    #+#             */
/*   Updated: 2023/01/31 18:18:17 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, t_data *data, t_costs *cost)
{
	find_data_a(*stack_a, data);
// except min and max element, push all others to stack B.
	while (data -> A_size > 3)
	{
		push_b(stack_a, stack_b, data);
		// if (((*stack_a) -> value != data -> min_A) && ((*stack_a) -> value != data -> max_A) &&  ((*stack_a) -> value != data -> median))
		// 	push_b(stack_a, stack_b, data);
		// else
		// 	rotate_a(stack_a, data);
	}
	if (is_sorted_a(*stack_a) != 0)
		three_number(stack_a, data);
	while (*stack_b)
	{
		shortest_way(*stack_a, *stack_b, data, cost);
		if (cost -> shortest_op == find_max(cost -> rot_a, cost -> rot_b))
		{
			while (cost -> rot_a > 0 && cost -> rot_b > 0)
			{
				rotate_ab(stack_a, stack_b, data);
				cost -> rot_a--;
				cost -> rot_b--;
			}
			while (cost -> rot_a > 0)
			{
				rotate_a(stack_a, data);
				cost -> rot_a--;
			}
			while (cost -> rot_b > 0)
			{
				rotate_b(stack_b, data);
				cost -> rot_b--;
			}
		}
		else if (cost -> shortest_op == cost -> rot_a + cost -> rev_rot_b)
		{
			while (cost -> rot_a > 0)
			{
				rotate_a(stack_a, data);
				cost -> rot_a--;
			}
			while (cost -> rev_rot_b > 0)
			{
				rev_rotate_b(stack_b, data);
				cost -> rev_rot_b--;
			}
		}
		else if (cost -> shortest_op == cost -> rev_rot_a + cost -> rot_b)
		{
			while (cost -> rev_rot_a > 0)
			{
				rev_rotate_a(stack_a, data);
				cost -> rev_rot_a--;
			}
			while (cost -> rot_b > 0)
			{
				rotate_b(stack_b, data);
				cost -> rot_b--;
			}
		}
		else if (cost -> shortest_op == find_max(cost -> rev_rot_a, cost -> rev_rot_b))
		{
			while (cost -> rev_rot_a > 0 && cost -> rev_rot_b > 0)
			{
				rev_rotate_ab(stack_a, stack_b, data);
				cost -> rev_rot_a--;
				cost -> rev_rot_b--;
			}
			while (cost -> rev_rot_a > 0)
			{
				rev_rotate_a(stack_a, data);
				cost -> rev_rot_a--;
			}
			while (cost -> rev_rot_b > 0)
			{
				rev_rotate_b(stack_b, data);
				cost -> rev_rot_b--;
			}
		}
		cost -> shortest_op = INT32_MAX;
		push_a(stack_a, stack_b, data);
	}
	last_sort(stack_a, data);
}



int	check_errors(int argc, char **argv)
{
	int i;
	
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

void	print_result(t_stack *stack_a, t_stack *stack_b, t_data data)
{
	ft_printf("\nA\tB\n-\t-\n");
	while (stack_a || stack_b)
	{	
		if (stack_a)
		{	ft_printf("%d", stack_a-> value);
			stack_a = stack_a -> next;
		}
		ft_printf("\t");
		if (stack_b)
		{
			ft_printf("%d", stack_b-> value);
			stack_b = stack_b -> next;
		}
		ft_printf("\n");
	}
	ft_printf("A_size : %d\nB_size : %d\nOperations : %d\n",data.A_size, data.B_size, data.operations);
}

int main (int argc, char **argv)
{
	t_stack	*stack_A;
	t_stack	*stack_B;
	t_data	data;
	t_costs cost;
	char	**ptr;
	int		count;
	int		*index;

	index = NULL;
	stack_A = NULL;
	stack_B = NULL;
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
		create_linklist(&stack_A, count + 1, ptr);
	}
	else if (argc > 1)
	{
		if (check_errors(argc, argv+1) == -1)
			return (0);
		index = find_index(argc, argv + 1);
		create_data(&data, &cost,argc);
		create_linklist(&stack_A, argc, argv + 1);
	}
	find_median(stack_A, &data, index);
	push_swap(&stack_A, &stack_B, &data, &cost);
	// print_result(stack_A, stack_B, data);
	return (0);
}
