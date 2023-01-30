/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:02:23 by sutku             #+#    #+#             */
/*   Updated: 2023/01/30 03:02:22 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ftprintf/ft_printf.h"

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
	int median;
}s_data;

typedef struct s_costs
{
	int	shortest_op;
	int rot_a;
	int rot_b;
	int rev_rot_a;
	int rev_rot_b;
}t_costs;

//Utils
void	create_linklist(s_stack **stack,int argc, char **argv);
void	create_data(s_data *data, t_costs *cost, int argc);
long int		long_atoi(char *str);
void	push_swap(s_stack **stack_a, s_stack **stack_b, s_data *data, t_costs *cost);
void	find_data_a(s_stack *stack, s_data *data);
// void	find_min_b(s_stack *stack, s_data *data);
// void	find_max_b(s_stack *stack, s_data *data);
void	find_median(s_stack *stack, s_data *data, int *index);
char	**ft_split(char const *s, char c);
void	is_duplicate(s_stack *stack);
int		is_duplicate_arr(char **argv);
int		is_integer(char *str);
void	*find_index(int argc, char **argv);
int		find_index_inA(s_stack  **stack_a, s_stack **stack_b);
int		is_sorted_a(s_stack *stack);
void	three_number(s_stack **stack, s_data *data);
int		min_index(s_stack *stack, s_data *data);
void	shortest_way(s_stack *stack_a, s_stack *stack_b, s_data *data, t_costs *cost);
int		find_max(int a, int b);
int		find_min(int a, int b);
void	last_sort(s_stack **stack, s_data *data);


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