/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:34:42 by sutku             #+#    #+#             */
/*   Updated: 2023/02/07 17:32:15 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker_commands(t_stack **stack_a, t_stack **stack_b, char *arr, t_data *data)
{
	if (ft_strncmp("ra\n", arr, 3) == 0)
		rotate_a(stack_a, data, 0);
	else if (ft_strncmp("rb\n", arr, 3) == 0)
		rotate_b(stack_b, data, 0);
	else if (ft_strncmp("rr\n", arr, 3) == 0)
		rotate_ab(stack_a, stack_b, data, 0);
	else if (ft_strncmp("rra\n", arr, 4) == 0)
		rev_rotate_a(stack_a, data, 0);
	else if (ft_strncmp("rrb\n", arr, 4) == 0)
		rev_rotate_b(stack_b, data, 0);
	else if (ft_strncmp("rrr\n", arr, 4)== 0)
		rev_rotate_ab(stack_a, stack_b, data, 0);
	else if (ft_strncmp("pa\n", arr, 3)== 0)
		push_a(stack_a, stack_b, data, 0);
	else if (ft_strncmp("pb\n", arr, 3) == 0)
		push_b(stack_a, stack_b, data, 0);
	else if (ft_strncmp("sa\n", arr, 3) == 0)
		swap_a(stack_a, data, 0);
	else if (ft_strncmp("sb\n", arr, 3) == 0)
		swap_b(stack_b, data, 0);
	else if (ft_strncmp("ss\n", arr, 3) == 0)
		swap_ab(stack_a, stack_b, data, 0);
	else
	{
		ft_printf("Error\n");
		free(arr);
		exit(-1);
	}
	
}


int	main(int argc, char **argv)
{
	t_stack	*checker_a;
	t_stack	*checker_b;
	t_data	c_data;
	int		len;
	char	*arr;

	checker_a = NULL;
	checker_b = NULL;
	arr = NULL;
	len = parsing(&checker_a, argc, argv);
	c_data.size_a = len;
	c_data.size_b = 0;
	if (len < 1)
		return (0);
	arr = get_next_line(0);
	while (arr != NULL)
	{
		checker_commands(&checker_a, &checker_b, arr, &c_data);
		free(arr);
		arr = get_next_line(0);	
	}
	if (is_sorted_a(checker_a) == 0 && c_data.size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	delete_ll(&checker_a);
	return (0);
}