/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:38:53 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/26 18:38:54 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_node **stack_a, t_node **stack_b, int len)
{
	if (len == 2)
	{
		if ((*stack_a)-> value > (*stack_a)-> next-> value)
			sa(stack_a);
	}
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4 || len == 5)
	{
		while (stack_size(*stack_a) > 3)
			push_min_to_b(stack_a, stack_b);
		sort_3(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

void	sort_3(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)-> value;
	y = (*a)-> next -> value;
	z = (*a)-> next -> next -> value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	push_min_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		min;
	int		index;
	int		pos;
	int		len;

	tmp = *stack_a;
	min = tmp -> value;
	index = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp -> value < min)
		{
			min = tmp -> value;
			pos = index;
		}
		index++;
		tmp = tmp -> next;
	}
	len = stack_size(*stack_a);
	exe_pushmintob (pos, len, stack_a, stack_b);
}

void	exe_pushmintob(int pos, int len, t_node **stack_a, t_node **stack_b)
{
	if (pos <= len / 2)
		while (pos-- > 0)
			ra(stack_a);
	else
		while (pos++ < len)
			rra(stack_a);
	pb(stack_a, stack_b);
}

int	sorting(t_node **stacka)
{
	t_node	*stackb;
	int		len;

	len = 0;
	stackb = NULL;
	len = stack_size(*stacka);
	if (len <= 5)
		sort_small_stack(stacka, &stackb, len);
	else
		push_process(stacka, &stackb);
	free_node (stackb);
	stackb = NULL;
	return (1);
}
