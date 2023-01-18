/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:02:23 by sutku             #+#    #+#             */
/*   Updated: 2023/01/15 22:42:06 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


typedef struct t_stack
{
	int value;
	struct t_stack *next;
}s_stack;

typedef struct t_data
{
	int	A_size;
	int	B_size;
	int	operations;
	int	min_A;
	int	max_A;
	int	min_B;
	int max_B;
}s_data;

//Utils
void	create_linklist(s_stack **stack_x,int argc, char **argv);
void	create_data(s_data *data, int argc);
int		ft_atoi(char *str);
// void	push_swap(s_stack **stack_x);
void	find_min_a(s_stack *stack, s_data *data);
void	find_min_b(s_stack *stack, s_data *data);
void	find_max_a(s_stack *stack, s_data *data);
void	find_max_b(s_stack *stack, s_data *data);

// Push Swap Operations
void	swap_a(s_stack **stack_A, s_data *data);
void	swap_b(s_stack **stack_B, s_data *data);
void	swap_ab(s_stack **stack_A, s_stack **stack_B, s_data *data);
void	push_a(s_stack **stack_A, s_stack **stack_B, s_data *data);
void	push_b(s_stack **stack_A, s_stack **stack_B, s_data *data);
void	rotate_a(s_stack **stack_A, s_data *data);
void	rotate_b(s_stack **stack_B, s_data *data);
void	rotate_ab(s_stack **stack_A, s_stack **stack_B, s_data *data);
void	rev_rotate_a(s_stack **stack_A, s_data *data);
void	rev_rotate_b(s_stack **stack_B, s_data *data);
void	rev_rotate_ab(s_stack **stack_A, s_stack **stack_B, s_data *data);