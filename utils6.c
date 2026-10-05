/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:35:56 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/29 17:44:43 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node *head)
{
	t_node	*current;
	t_node	*next_node;

	if (!head)
		return ;
	current = head;
	while (current)
	{
		next_node = current -> next;
		free (current);
		current = NULL;
		current = next_node;
	}
	head = NULL;
}

int	stack_size(t_node *head)
{
	t_node	*current;
	int		i;

	i = 0;
	if (!head)
		return (0);
	current = head;
	while (current)
	{
		current = current -> next;
		i++;
	}
	return (i);
}

int	print_stack_value(t_node *head)
{
	t_node	*current;
	int		i;

	i = 0;
	if (!head)
		return (0);
	current = head;
	while (current)
	{
		current = current -> next;
		i++;
	}
	return (i);
}

void	execute_push_two(t_node **a, t_node **b, int stacksize)
{
	int	count;
	int	pushed;
	int	pone;
	int	ptwo;
	int	pthree;

	pushed = 0;
	count = stacksize - 1;
	pone = stacksize / 4;
	ptwo = (stacksize * 2) / 4;
	pthree = (stacksize * 3) / 4;
	while (pushed < stacksize)
	{
		push_first(a, b, count, stacksize);
		pushed++;
	}
	push_remaining(a, b, count, pthree);
	if (((*a)->next->location) < ((*a)->location))
		sa(a);
}

void	push_remaining(t_node **a, t_node **b,	int count, int pthree)
{
	int	stacksize;

	stacksize = 0;
	stacksize = stack_size(*a);
	while (stacksize != 2)
	{
		if ((*a)-> location == 0 || (*a)-> location == count)
			ra(a);
		else if ((*a)-> location >= pthree)
		{
			pb(a, b);
			rb(b);
			stacksize--;
		}
		else
		{
			pb(a, b);
			stacksize--;
		}
	}
}
