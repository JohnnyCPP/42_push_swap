/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:01:23 by jonnavar          #+#    #+#             */
/*   Updated: 2024/01/25 16:04:12 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_hlen(unsigned int value)
{
	int	length;

	length = 0;
	while (value)
	{
		length ++;
		value /= 16;
	}
	return (length);
}

static	void	ft_lch(unsigned int value)
{
	if (value >= 16)
	{
		ft_lch(value / 16);
		ft_lch(value % 16);
	}
	else if (value < 10)
		ft_putchar_fd(value + '0', 1);
	else
		ft_putchar_fd((value - 10) + 'a', 1);
}

void	ft_print_lch(va_list args, int *count)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_lch(value);
	*count += ft_hlen(value);
}
