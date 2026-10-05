/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:38:39 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/26 18:38:49 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costa(t_node **a, t_node *currentb)
{
	t_node	*currenta;
	int		countstepa;

	currenta = *a;
	countstepa = 0;
	while (currenta->location < currentb->location)
	{
		countstepa++;
		currenta = currenta->next;
	}
	currentb->costa = countstepa;
}

void	calculate_negative_costa(t_node **a, t_node *currentb)
{
	t_node	*currenta;
	int		countstepa;

	currenta = *a;
	countstepa = 0;
	while (currenta->prev->location > currentb->location)
	{
		countstepa--;
		currenta = currenta->prev;
	}
	currentb->costa = countstepa;
}

void	calculate_b(t_node **a, t_node **b)
{
	t_node	*currentb;
	t_node	*currenta;
	int		sizeb;
	int		countstepb;

	countstepb = 0;
	sizeb = stack_size(*b);
	currentb = *b;
	currenta = *a;
	while (currentb)
	{
		currentb->costa = 0;
		currentb->costb = 0;
		if (countstepb <= sizeb / 2)
			currentb->costb = countstepb;
		else
			currentb->costb = (-1) * (sizeb - countstepb);
		if (currenta->location < currentb->location)
			calculate_costa(a, currentb);
		else
			calculate_negative_costa(a, currentb);
		countstepb++;
		currentb = currentb->next;
	}
	calculate_total(b);
}

int	handle_error(int *s_arr, int *t_arr, t_node *head)
{
	if (s_arr)
		free(s_arr);
	if (t_arr)
		free(t_arr);
	if (head)
		free_node(head);
	return (1);
}

t_node	*create_new_node(int count, int *t_arr, int *s_arr, int t_a_size)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->index = count;
	new_node->value = t_arr[count];
	new_node->next = NULL;
	new_node->location = getindex(t_arr[count], s_arr, t_a_size);
	return (new_node);
}
