/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:55:21 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/02 17:56:00 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_to_binary(const long number)
{
	char			*binary_string;
	long			copy_of_number;
	unsigned long	bit_index;
	int				bit;

	binary_string = (char *) ft_calloc(BITS_IN_LONG + 1, sizeof(char));
	if (!binary_string)
		return (NULL);
	copy_of_number = number;
	bit_index = 0;
	while (bit_index < BITS_IN_LONG)
	{
		bit = copy_of_number & (long) 1;
		if (bit)
			binary_string[BITS_IN_LONG - 1 - bit_index] = '1';
		else
			binary_string[BITS_IN_LONG - 1 - bit_index] = '0';
		copy_of_number >>= 1;
		bit_index ++;
	}
	binary_string[BITS_IN_LONG] = '\0';
	return (binary_string);
}
