/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:39:08 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/26 18:39:09 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*selectsmallest(t_node **b)
{
	t_node	*current;
	t_node	*smallnode;

	current = *b;
	smallnode = current;
	while (current)
	{
		if (current ->costtotal < smallnode->costtotal)
			smallnode = current;
		current = current->next;
	}
	return (smallnode);
}

int	max_number(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a < b)
		return (b);
	else
		return (a);
}

void	calculate_total(t_node **b)
{
	t_node	*curr;

	curr = *b;
	while (curr)
	{
		if ((curr->costa <= 0 && curr->costb <= 0)
			|| (curr->costa >= 0 && curr->costb >= 0))
			curr->costtotal = max_number(curr->costa, curr->costb);
		else
		{
			curr->costtotal = curr->costa - curr->costb;
			if (curr->costtotal < 0)
				curr->costtotal = -1 * curr->costtotal;
		}
		curr = curr->next;
	}
}

void	push_process(t_node **stacka, t_node **stackb)
{
	int	stacksize;

	stacksize = stack_size(*stacka);
	if (stacksize <= 100)
		execute_push_one(stacka, stackb, stacksize);
	else
		execute_push_two(stacka, stackb, stacksize);
	sorting_process(stacka, stackb);
	while ((*stacka)->location != 0)
		ra(stacka);
}

t_node	*add_node_to_stack(t_node *head, t_node *each_node)
{
	t_node	*current;

	if (!head)
		return (each_node);
	else
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = each_node;
	}
	return (head);
}
