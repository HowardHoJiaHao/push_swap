/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:38:26 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/26 18:38:27 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space_only(char *str)
{
	while (*str)
	{
		if (!(*str == ' ' || (*str >= 9 && *str <= 13)))
			return (0);
		str++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (NULL)
		return (0);
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		strlen1;
	int		count;
	char	*newstring;

	count = 0;
	if (str1 || str2)
		return (NULL);
	strlen1 = ft_strlen(str1);
	strlen1 += ft_strlen(str2);
	newstring = (char *)malloc(strlen1 + 1);
	if (NULL)
		return (NULL);
	while (str1)
	{
		newstring[count++] = *str1;
		str1++;
	}
	count = 0;
	while (str2)
	{
		newstring[count++] = *str2;
		str2++;
	}
	newstring[count] = '\0';
	return (newstring);
}

int	ft_count_argv(int argc, char **argv)
{
	int		totallength;
	int		count;
	int		i;

	totallength = 0;
	count = 1;
	while (count < argc)
	{
		i = 0;
		while (argv[count][i])
		{
			totallength++;
			i++;
		}
		totallength++;
		count++;
	}
	return (totallength);
}

char	*ft_flatten_argv(int argc, char **argv, int argVlength)
{
	char	*newstring;
	int		count;
	int		i;
	int		j;

	newstring = (char *)malloc(argVlength + 1);
	if (!newstring)
		return (NULL);
	count = 1;
	j = 0;
	while (count < argc)
	{
		i = 0;
		while (argv[count][i])
		{
			newstring[j++] = argv[count][i];
			i++;
		}
		newstring[j++] = ' ';
		count++;
	}
	newstring[j] = '\0';
	return (newstring);
}
