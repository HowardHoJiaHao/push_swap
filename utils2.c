/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:33:10 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/08/26 18:33:11 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countword(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == ' ')
		{
			str++;
		}
		if (*str > 32 && *str < 127)
		{
			count++;
			str++;
		}
		while (*str > 32 && *str < 127)
		{
			str++;
		}
	}
	return (count);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long	ft_str_to_long(char *nptr)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * num);
}

char	*put_word(char **oristr)
{
	int		len;
	char	*word_start;
	char	*eachword;
	int		i;

	len = 0;
	i = 0;
	word_start = *oristr;
	while (**oristr > 32 && **oristr < 127)
	{
		len++;
		(*oristr)++;
	}
	eachword = (char *)malloc(sizeof(char) * (len + 1));
	if (!eachword)
		return (NULL);
	while (i < len)
	{
		eachword[i] = word_start[i];
		i++;
	}
	eachword[len] = '\0';
	return (eachword);
}

char	**ft_split(char *oristr)
{
	int		word_count;
	char	**split_word;
	int		i;

	i = 0;
	if (!oristr)
		return (NULL);
	word_count = countword(oristr);
	split_word = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split_word)
		return (NULL);
	while (i < word_count)
	{
		while (*oristr == ' ')
			oristr++;
		split_word[i] = put_word(&oristr);
		if (!split_word[i])
		{
			free_split_words(split_word);
			return (NULL);
		}
		i++;
	}
	split_word[i] = NULL;
	return (split_word);
}
