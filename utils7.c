/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:38:45 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/29 12:36:02 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stack(int *s_arr, int *t_arr, int t_a_size, t_node **stacka)
{
	t_node	*head;
	t_node	*each_node;
	int		count;

	head = NULL;
	count = 0;
	while (count < t_a_size)
	{
		each_node = create_new_node(count, t_arr, s_arr, t_a_size);
		if (!each_node)
			return (handle_error(s_arr, t_arr, head));
		head = add_node_to_stack(head, each_node);
		count++;
	}
	*stacka = head;
	return (0);
}

void	duplicate_array(int *dup_arr, int *track_arr, int track_arr_size)
{
	int	count;

	count = 0;
	while (count < track_arr_size)
	{
		dup_arr[count] = track_arr[count];
		count++;
	}
}

int	getindex(int findnumber, int *sorted_arr, int track_arr_size)
{
	int	count;

	count = 0;
	while (count < track_arr_size)
	{
		if (sorted_arr[count] == findnumber)
		{
			return (count);
		}
		count++;
	}
	return (-1);
}

void	make_circular(t_node **astack)
{
	t_node	*current;
	t_node	*last;

	current = *astack;
	while (current->next)
		current = current -> next;
	last = current;
	current = *astack;
	while (current)
	{
		current->prev = last;
		last = current;
		current = current ->next;
	}
}

void	sorting_process(t_node **a, t_node **b)
{
	int		sizeb;
	t_node	*smallnode;

	sizeb = stack_size(*b);
	while (sizeb)
	{
		make_circular(a);
		calculate_b(a, b);
		smallnode = selectsmallest(b);
		apply_rotations(a, b, smallnode);
		pa(a, b);
		sizeb--;
	}
}
