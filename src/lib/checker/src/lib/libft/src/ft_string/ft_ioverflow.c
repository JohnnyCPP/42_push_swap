/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ioverflow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:10:23 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/30 20:10:36 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_out_of_bounds(int *buffer, int digit, int sign)
{
	if (*buffer > INT_MAX / 10)
		return (1);
	else if (*buffer == INT_MAX / 10)
	{
		if (sign == 1 && digit > INT_MAX % 10)
			return (1);
		else if (sign == -1 && digit > -(INT_MIN % 10))
			return (1);
	}
	return (0);
}

static	int	ft_add_value(const char *value, int *index, int *buffer, int s)
{
	int	overflows;
	int	digit;

	digit = value[*index] - '0';
	overflows = ft_out_of_bounds(buffer, digit, s);
	if (overflows)
		return (1);
	*buffer *= 10;
	*buffer += digit;
	(*index)++;
	return (0);
}

int	ft_ioverflow(const char *value)
{
	int		overflows;
	int		index;
	int		buffer;
	int		sign;

	overflows = 0;
	if (!value)
		return (overflows);
	index = 0;
	buffer = 0;
	sign = 1;
	if (value[index] == '-')
	{
		sign *= -1;
		index ++;
	}
	while (ft_isdigit(value[index]))
	{
		overflows = ft_add_value(value, &index, &buffer, sign);
		if (overflows)
			break ;
	}
	if (overflows && sign == -1)
		return (-1);
	return (overflows);
}
