/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:32:31 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/29 12:36:56 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	first = *stack_a;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || !*stack_b || !(*stack_b)-> next)
		return ;
	first = *stack_b;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*tail;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	first = *stack_a;
	*stack_a = first -> next;
	tail = *stack_a;
	while (tail -> next)
		tail = tail -> next;
	tail -> next = first;
	first -> next = NULL;
	write(1, "ra\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*first_a;
	t_node	*tail_a;
	t_node	*first_b;
	t_node	*tail_b;

	if (!stack_a || !*stack_a || !(*stack_a)-> next || !stack_b || !*stack_b)
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	*stack_a = first_a -> next;
	*stack_b = first_b -> next;
	tail_a = *stack_a;
	tail_b = *stack_b;
	while (tail_a -> next)
		tail_a = tail_a -> next;
	while (tail_b -> next)
		tail_b = tail_b -> next;
	tail_a -> next = first_a;
	first_a -> next = NULL;
	tail_b -> next = first_b;
	first_b -> next = NULL;
	write(1, "rr\n", 3);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	t_node	*prev_a;
	t_node	*current_a;
	t_node	*prev_b;
	t_node	*current_b;

	if (!stack_a || !*stack_a || !(*stack_a)-> next || !stack_b || !*stack_b)
		return ;
	current_a = *stack_a;
	while (current_a -> next)
	{
		prev_a = current_a;
		current_a = current_a -> next;
	}
	prev_a -> next = NULL;
	current_a -> next = *stack_a;
	*stack_a = current_a;
	current_b = *stack_b;
	while (current_b -> next)
	{
		prev_b = current_b;
		current_b = current_b -> next;
	}
	prev_b -> next = NULL;
	current_b -> next = *stack_b;
	*stack_b = current_b;
}
