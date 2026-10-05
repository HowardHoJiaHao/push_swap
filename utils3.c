/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:37:43 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/29 12:37:41 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_string(char **str, int returntype)
{
	free(*str);
	write(2, "Error\n", 6);
	return (returntype);
}

int	error_int(int **str, int returntype)
{
	free(*str);
	write(2, "Error\n", 6);
	return (returntype);
}

int	error_free(int **int_ptr)
{
	free(*int_ptr);
	write(2, "Error\n", 6);
	return (1);
}

void	apply_rotations(t_node **a, t_node **b, t_node *smallnode)
{
	smallnode = selectsmallest(b);
	while (smallnode-> costa > 0 && smallnode-> costb > 0)
	{
		smallnode-> costa--;
		smallnode-> costb--;
		rr(a, b);
	}
	while (smallnode-> costa < 0 && smallnode-> costb < 0)
	{
		smallnode-> costa++;
		smallnode-> costb++;
		rrr(a, b);
		write(1, "rrr\n", 4);
	}
	apply_rotations_t(a, b, smallnode);
}

void	apply_rotations_t(t_node **a, t_node **b, t_node *smallnode)
{
	while (smallnode-> costa > 0)
	{
		smallnode-> costa--;
		ra(a);
	}
	while (smallnode-> costb > 0)
	{
		smallnode-> costb--;
		rb(b);
	}
	while (smallnode-> costa < 0)
	{
		smallnode-> costa++;
		rra(a);
	}
	while (smallnode-> costb < 0)
	{
		smallnode-> costb++;
		rrb(b);
	}
}
