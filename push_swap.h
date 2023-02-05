/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:02:23 by sutku             #+#    #+#             */
/*   Updated: 2023/02/05 01:53:05 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ftprintf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}t_stack;

typedef struct s_data
{
	int	size_a;
	int	size_b;
	int	operations;
	int	min_a;
	int	max_a;
	int	median;
}t_data;

typedef struct s_costs
{
	int	shortest_op;
	int	rot_a;
	int	rot_b;
	int	rev_rot_a;
	int	rev_rot_b;
	int	op[4];
}t_costs;

//Utils
long int	long_atoi(char *str);
int			check_errors(t_stack *stack, int argc, char **argv, int len);
void		create_linklist(t_stack **stack, int argc, char **argv);
void		create_data(t_data *data, t_costs *cost, int argc);
void		push_swap(t_stack **stack_a, t_stack **stack_b, int len);
void		delete_ll(t_stack **stack_a);
void		find_data_a(t_stack *stack, t_data *data);
void		find_median(t_stack *stack, t_data *data, int *index);
char		**ft_split(char const *s, char c);
int			is_duplicate(t_stack *stack, int a, int len);
int			is_duplicate_arr(char **argv);
int			is_integer(char *str);
void		*find_index(int argc, int *argv);
int			find_index_in_a(t_stack *stack_a, t_stack *stack_b, t_data *data);
int			is_sorted_a(t_stack *stack);
void		three_number(t_stack **stack, t_data *data);
int			min_index(t_stack *stack, t_data *data);
void		shortest_way(t_stack *stack_a, t_stack *stack_b,
				t_data *data, t_costs *cost);
int			find_max(int a, int b);
int			find_min(int a, int b);
void		last_sort(t_stack **stack, t_data *data);
void		calculate_op(int min, t_costs *cost);
void		check_contions(t_stack **stack_a, t_stack **stack_b,
				t_data *data, t_costs *cost);
void		find_median_arr(t_stack *stack, int len, t_data *data);
int			parsing(t_stack **stack_a, int argc, char **argv);
//Push Swap Conditions
void		push_c0(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		c1(t_stack **stack_a, t_stack **stack_b, t_data *data,
				t_costs *cost);
void		c2(t_stack **stack_a, t_stack **stack_b, t_data *data,
				t_costs *cost);
void		c3(t_stack **stack_a, t_stack **stack_b, t_data *data,
				t_costs *cost);
void		c4(t_stack **stack_a, t_stack **stack_b, t_data *data,
				t_costs *cost);

// Push Swap Operations
void		swap_a(t_stack **stack_a, t_data *data);
void		swap_b(t_stack **stack_b, t_data *data);
void		swap_ab(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		push_a(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		push_b(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		rotate_a(t_stack **stack_a, t_data *data);
void		rotate_b(t_stack **stack_b, t_data *data);
void		rotate_ab(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		rev_rotate_a(t_stack **stack_a, t_data *data);
void		rev_rotate_b(t_stack **stack_b, t_data *data);
void		rev_rotate_ab(t_stack **stack_a, t_stack **stack_b, t_data *data);

#endif