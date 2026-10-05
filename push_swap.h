/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:38:20 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/29 17:55:44 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				index;
	int				value;
	int				location;
	int				costa;
	int				costb;
	int				costtotal;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct data_node	*f_node;
	struct data_node	*l_node;
	int					len;
}	t_stack;

int		is_space_only(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_count_argv(int argc, char **argv);
char	*ft_flatten_argv(int argc, char **argv, int argVlength);
int		ft_isdigit(int c);
char	**ft_split(char *oristr);
long	ft_str_to_long(char *nptr);
int		ft_con_str_to_int_ary(int **ary, char **str);
int		ft_count_str(char **str);
int		error_string(char **str, int returntype);
int		error_int(int **str, int returntype);
int		has_duplicates(int *array, int size);
int		is_sorted(int *array, int size);
int		make_stack(int **track_arr, int track_arr_size, t_node **stacka);
int		create_stack(int *s_arr, int *t_arr, int t_a_size, t_node **stacka);
int		getindex(int findnumber, int *sorted_arr, int track_arr_size);
int		print_stack_value(t_node *head);
int		stack_size(t_node *head);
void	free_node(t_node *head);
void	duplicate_array(int *dup_arr, int *track_arr, int track_arr_size);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
int		sorting(t_node **stacka);
void	push_process(t_node **stacka, t_node **stackb);
void	sorting_process(t_node **a, t_node **b);
void	make_circular(t_node **astack);
void	free_split_words(char **split_word);
void	sort_small_stack(t_node **stack_a, t_node **stack_b, int len);
void	sort_3(t_node **a);
void	push_min_to_b(t_node **stack_a, t_node **stack_b);
void	exe_pushmintob(int pos, int len, t_node **stack_a, t_node **stack_b);
void	calculate_b( t_node **a, t_node **b);
t_node	*selectsmallest(t_node **b);
void	calculate_total(t_node **b);
void	apply_rotations(t_node **a, t_node **b, t_node *smallnode);
void	apply_rotations_t(t_node **a, t_node **b, t_node *smallnode);
void	calculate_costa(t_node **a, t_node *currentb);
void	calculate_negative_costa(t_node **a, t_node *currentb);
int		handle_error(int *s_arr, int *t_arr, t_node *head);
int		create_stack(int *s_arr, int *t_arr, int t_a_size, t_node **stacka);
t_node	*add_node_to_stack(t_node *head, t_node *each_node);
t_node	*create_new_node(int count, int *t_arr, int *s_arr, int t_a_size);
void	execute_push_one(t_node **a, t_node **b, int stacksize);
void	execute_push_two(t_node **a, t_node **b, int stacksize);
void	push_remaining(t_node **a, t_node **b,	int count, int pthree);
void	push_first(t_node **a, t_node **b,	int count, int stacksize);
int		convert_helper(int i, int **ary, char **str);
int		is_valid_number(char *str);

#endif