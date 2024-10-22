/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:13:34 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/29 16:13:45 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strcmp(const char *string_1, const char *string_2)
{
	size_t			index;
	unsigned char	*str1_copy;
	unsigned char	*str2_copy;

	index = 0;
	str1_copy = (unsigned char *) string_1;
	str2_copy = (unsigned char *) string_2;
	while (str1_copy[index] || str2_copy[index])
	{
		if (str2_copy[index] != str1_copy[index])
			return (str1_copy[index] - str2_copy[index]);
		index ++;
	}
	return (0);
}
