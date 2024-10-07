/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:05:35 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/01 20:14:24 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_subs_len(const char *string, const char character)
{
	int	index;

	index = 0;
	while (string[index] != 0)
	{
		if (string[index] == character)
			return (index);
		index ++;
	}
	return (index);
}

static	int	ft_len(const char *string, const char character)
{
	int	index;
	int	length;

	index = 1;
	length = 1;
	while (string[index] != 0)
	{
		if (string[index - 1] != 0 && string[index + 1] != 0)
			if (string[index] == character)
				length ++;
		index ++;
	}
	return (length);
}

char	**ft_split(const char *str, const char c)
{
	int		l_substr;
	int		start;
	int		end;
	int		index_j;
	char	**result;

	if (!str)
		return ((void *) 0);
	result = (char **) ft_calloc(ft_len(str, c) + 1, sizeof(char *));
	l_substr = ft_subs_len(str + 1, c);
	start = 0;
	end = l_substr + 1;
	index_j = 0;
	if (str[start] == c)
		start ++;
	result[index_j ++] = ft_substr(str, start, l_substr);
	start += l_substr + 1;
	while (str[end] != 0)
	{
		l_substr = ft_subs_len(str + (end + 1), c);
		end += l_substr + 1;
		result[index_j ++] = ft_substr(str, start, l_substr);
		start += l_substr + 1;
	}
	return (result);
}
