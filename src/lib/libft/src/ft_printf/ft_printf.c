/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:36:34 by jonnavar          #+#    #+#             */
/*   Updated: 2024/01/13 06:44:43 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_handle_pholder(char ph, va_list args, int *i, int *count)
{
	if (ph == '-' || ft_isdigit(ph) || ph == '.')
		ft_no_ph(i, count);
	else if (ph == 'c' || ph == 's' || ph == 'p')
		ft_str_ph(ph, args, i, count);
	else if (ph == 'd' || ph == 'i' || ph == 'u')
		ft_num_ph(ph, args, i, count);
	else if (ph == '%')
		ft_ph_ph(i, count);
	else if (ph == 'x' || ph == 'X')
		ft_base_ph(ph, args, i, count);
	else
		ft_no_ph(i, count);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_handle_pholder(format[i + 1], args, &i, &count);
		else
		{
			ft_putchar_fd(format[i], 1);
			i ++;
			count ++;
		}
	}
	va_end(args);
	return (count);
}
