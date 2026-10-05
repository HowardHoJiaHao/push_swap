/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:33:52 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/26 18:33:53 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = temp -> next;
	temp -> next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = temp -> next;
	temp -> next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	rb(t_node **stack_b)
{
	t_node	*head;
	t_node	*tail;

	if (!stack_b || !*stack_b || !(*stack_b)-> next)
		return ;
	head = *stack_b;
	*stack_b = head -> next;
	tail = *stack_b;
	while (tail -> next)
		tail = tail -> next;
	tail -> next = head;
	head -> next = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_node **stack_a)
{
	t_node	*prev;
	t_node	*current;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	current = *stack_a;
	while (current -> next)
	{
		prev = current;
		current = current -> next;
	}
	prev -> next = NULL;
	current -> next = *stack_a;
	*stack_a = current;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	t_node	*prev;
	t_node	*current;

	if (!stack_b || !*stack_b || !(*stack_b)-> next)
		return ;
	current = *stack_b;
	while (current -> next)
	{
		prev = current;
		current = current -> next;
	}
	prev -> next = NULL;
	current -> next = *stack_b;
	*stack_b = current;
	write(1, "rrb\n", 4);
}
