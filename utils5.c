/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:39:39 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/29 17:56:32 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_con_str_to_int_ary(int **ary, char **str)
{
	int		i;
	int		strcnt;

	i = 0;
	strcnt = 0;
	while (str[strcnt])
		strcnt++;
	*ary = (int *)malloc(sizeof(int) * strcnt);
	if (*ary == NULL)
	{
		free_split_words(str);
		return (1);
	}
	while (i < strcnt)
	{
		if (convert_helper(i, ary, str))
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_str(char **str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		i++;
	}
}

int	make_stack(int **track_arr, int track_arr_size, t_node **stacka)
{
	int	*sorted_arr;

	sorted_arr = malloc (sizeof(int) * track_arr_size);
	if (!sorted_arr)
		return (error_int(track_arr, 1));
	duplicate_array(sorted_arr, *track_arr, track_arr_size);
	sort_array(sorted_arr, track_arr_size);
	if (create_stack(sorted_arr, *track_arr, track_arr_size, stacka))
		return (1);
	free (sorted_arr);
	sorted_arr = NULL;
	free (*track_arr);
	*track_arr = NULL;
	if (sorting(stacka))
	{
		free_node(*stacka);
		return (1);
	}
	free_node(*stacka);
	*stacka = NULL;
	return (1);
}
