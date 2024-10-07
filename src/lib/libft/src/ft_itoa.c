/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:05:35 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/01 20:14:24 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*ft_convert(int index, int sign, long value)
{
	char	*pointer;

	pointer = (char *) ft_calloc(index + 1, sizeof(char));
	if (!pointer)
		return ((void *) 0);
	if (sign < 0)
		pointer[0] = '-';
	index --;
	while (value)
	{
		pointer[index --] = (value % 10) + 48;
		value /= 10;
	}
	return (pointer);
}

static	int	ft_itoa_len(int value)
{
	int	auxiliar;
	int	length;

	auxiliar = value;
	length = 0;
	while (auxiliar)
	{
		auxiliar /= 10;
		length ++;
	}
	return (length);
}

static	char	*ft_handle_min(void)
{
	int		index;

	index = ft_itoa_len(INT_MAX);
	return (ft_convert(index + 1, -1, (unsigned int) INT_MAX + 1));
}

char	*ft_itoa(int value)
{
	int		index;
	int		sign;
	char	*pointer;

	if (!value)
	{
		pointer = (char *) ft_calloc(1, sizeof(char));
		if (!pointer)
			return ((void *) 0);
		pointer[0] = '0';
		return (pointer);
	}
	else if (value == INT_MIN)
		return (ft_handle_min());
	index = ft_itoa_len(value);
	sign = 1;
	if (value < 0)
	{
		index ++;
		sign *= -1;
		value *= -1;
	}
	return (ft_convert(index, sign, value));
}
