/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:32:45 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/29 17:56:47 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_push_one(t_node **a, t_node **b, int stacksize)
{
	int	count;
	int	pushed;
	int	ptwo;

	pushed = 0;
	count = stacksize - 1;
	ptwo = (stacksize * 2) / 4;
	while (pushed < stacksize)
	{
		if ((*a)-> location == 0 || (*a)-> location == count)
			ra(a);
		else if ((*a)-> location >= ptwo)
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
		pushed++;
	}
	if (((*a)->next->location) < ((*a)->location))
		sa(a);
}

void	push_first(t_node **a, t_node **b,	int count, int stacksize)
{
	int	pone;
	int	ptwo;
	int	pthree;

	pone = stacksize / 4;
	ptwo = (stacksize * 2) / 4;
	pthree = (stacksize * 3) / 4;
	if ((*a)-> location == 0 || (*a)-> location == count)
		ra(a);
	else if ((*a)-> location >= ptwo && (*a)-> location < pthree)
	{
		pb(a, b);
		rb(b);
	}
	else if ((*a)-> location >= pone && (*a)-> location < ptwo)
		pb(a, b);
	else
		ra(a);
}

int	convert_helper(int i, int **ary, char **str)
{
	ssize_t	tempt;

	if (!is_valid_number(str[i]))
	{
		free_split_words (str);
		return (free(*ary), 1);
	}
	tempt = ft_str_to_long((char *)str[i]);
	if (tempt < INT_MIN || tempt > INT_MAX)
	{
		free_split_words (str);
		return (free(*ary), 1);
	}
	(*ary)[i] = (int)tempt;
	return (0);
}
