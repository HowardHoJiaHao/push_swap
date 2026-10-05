/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:38:06 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/28 16:20:30 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	data_init(int argc, char **argv, int **track_arr, int *track_arr_size)
{
	char	*flat_string;
	int		arg_total_length;
	char	**number_string;
	int		*arr_int;
	int		onoffis;

	arr_int = NULL;
	arg_total_length = ft_count_argv(argc, argv);
	flat_string = ft_flatten_argv(argc, argv, arg_total_length);
	if (!flat_string)
		return (1);
	number_string = ft_split(flat_string);
	if (!number_string)
		return (free(flat_string), 1);
	free(flat_string);
	onoffis = ft_con_str_to_int_ary(&arr_int, number_string);
	if (onoffis)
		return (1);
	*track_arr = arr_int;
	*track_arr_size = ft_count_str(number_string);
	free_split_words (number_string);
	return (0);
}

int	main(int argc, char **argv)
{
	int		*track_arr;
	int		track_arr_size;
	t_node	*stacka;

	stacka = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && (argv[1][0] == '\0' || is_space_only(argv[1])))
		return (write(2, "Error\n", 6), 1);
	if (data_init(argc, argv, &track_arr, &track_arr_size))
		return (write(2, "Error\n", 6), 1);
	if (has_duplicates(track_arr, track_arr_size))
		return (error_int(&track_arr, 1));
	if (is_sorted(track_arr, track_arr_size))
		return (free(track_arr), 0);
	if (!make_stack(&track_arr, track_arr_size, &stacka))
		return (1);
	return (0);
}

// ./push_swap $(shuf -i 1-100 -n 100 | tee numbers.txt) >output.txt
// ./push_swap $(cat numbers.txt) >output.txt |
// valgrind --leak-check=full ./push_swap "7 2 0 1 8 5 12 3 13 4 9 14 11 6 10"