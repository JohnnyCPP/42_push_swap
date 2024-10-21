/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_to_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	*ps_args_to_numbers(const int argc, const char **argv)
{
	const char	*argument;
	int			*numbers;
	int			iterator;

	numbers = (int *) ft_calloc(argc - 1, sizeof(int));
	if (!numbers)
		return (NULL);
	iterator = 0;
	while (iterator < argc - 1)
	{
		argument = *(argv + iterator + 1);
		numbers[iterator] = ft_atoi(argument);
		iterator ++;
	}
	return (numbers);
}
