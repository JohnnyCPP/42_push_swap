/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uch.c                                     :+:      :+:    :+:   */
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

static	void	ft_uch(unsigned int value)
{
	if (value >= 16)
	{
		ft_uch(value / 16);
		ft_uch(value % 16);
	}
	else if (value < 10)
		ft_putchar_fd(value + '0', 1);
	else
		ft_putchar_fd((value - 10) + 'A', 1);
}

void	ft_print_uch(va_list args, int *count)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_uch(value);
	*count += ft_hlen(value);
}
