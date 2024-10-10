/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:13:34 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/29 16:13:45 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strncmp(const char *ptr_find, const char *ptr_str, size_t length)
{
	size_t			index;
	unsigned char	*aux1;
	unsigned char	*aux2;

	if (!ptr_find || !ptr_str)
		return (0);
	index = 0;
	aux1 = (unsigned char *) ptr_find;
	aux2 = (unsigned char *) ptr_str;
	while ((aux2[index] != 0 || aux1[index] != 0) && index < length)
	{
		if (aux2[index] != aux1[index])
			return (aux1[index] - aux2[index]);
		index ++;
	}
	return (0);
}
