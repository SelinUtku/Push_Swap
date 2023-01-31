/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:02:23 by sutku             #+#    #+#             */
/*   Updated: 2023/01/31 15:49:06 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ftprintf/ft_printf.h"

typedef struct s_stack
{
	int value;
	struct s_stack *next;
}t_stack;

typedef struct s_data
{
	int	A_size;
	int	B_size;
	int	operations;
	int	min_A;
	int	max_A;
	int	min_B;
	int max_B;
	int median;
}t_data;

typedef struct s_costs
{
	int	shortest_op;
	int rot_a;
	int rot_b;
	int rev_rot_a;
	int rev_rot_b;
}t_costs;

//Utils
void	create_linklist(t_stack **stack,int argc, char **argv);
void	create_data(t_data *data, t_costs *cost, int argc);
long int		long_atoi(char *str);
void	push_swap(t_stack **stack_a, t_stack **stack_b, t_data *data, t_costs *cost);
void	find_data_a(t_stack *stack, t_data *data);
// void	find_min_b(t_stack *stack, t_data *data);
// void	find_max_b(t_stack *stack, t_data *data);
void	find_median(t_stack *stack, t_data *data, int *index);
char	**ft_split(char const *s, char c);
void	is_duplicate(t_stack *stack);
int		is_duplicate_arr(char **argv);
int		is_integer(char *str);
void	*find_index(int argc, char **argv);
int		find_index_inA(t_stack  *stack_a, t_stack *stack_b, t_data *data);
int		is_sorted_a(t_stack *stack);
void	three_number(t_stack **stack, t_data *data);
int		min_index(t_stack *stack, t_data *data);
void	shortest_way(t_stack *stack_a, t_stack *stack_b, t_data *data, t_costs *cost);
int		find_max(int a, int b);
int		find_min(int a, int b);
void	last_sort(t_stack **stack, t_data *data);


// Push Swap Operations
void	swap_a(t_stack **stack_A, t_data *data);
void	swap_b(t_stack **stack_B, t_data *data);
void	swap_ab(t_stack **stack_A, t_stack **stack_B, t_data *data);
void	push_a(t_stack **stack_A, t_stack **stack_B, t_data *data);
void	push_b(t_stack **stack_A, t_stack **stack_B, t_data *data);
void	rotate_a(t_stack **stack_A, t_data *data);
void	rotate_b(t_stack **stack_B, t_data *data);
void	rotate_ab(t_stack **stack_A, t_stack **stack_B, t_data *data);
void	rev_rotate_a(t_stack **stack_A, t_data *data);
void	rev_rotate_b(t_stack **stack_B, t_data *data);
void	rev_rotate_ab(t_stack **stack_A, t_stack **stack_B, t_data *data);