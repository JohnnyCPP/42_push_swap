/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	int	ps_is_duplicated(const int *num, const int *nums, const int size)
{
	int	current_number;
	int	times_spotted;
	int	iterator;

	times_spotted = 0;
	iterator = 0;
	while (iterator < size)
	{
		current_number = nums[iterator];
		if (current_number == *num)
			times_spotted ++;
		if (times_spotted > 1)
			return (1);
		iterator ++;
	}
	return (0);
}

int	ps_contains_duplicates(const int *numbers, const int size)
{
	const int	*number;
	int			is_duplicated;
	int			iterator;

	iterator = 0;
	number = numbers;
	while (iterator < size && number)
	{
		is_duplicated = ps_is_duplicated(number, numbers, size);
		if (is_duplicated)
			return (1);
		iterator ++;
		number = numbers + iterator;
	}
	return (0);
}

static	int	ps_is_numeric(const char *arg)
{
	int		is_valid;
	int		char_index;
	char	character;

	is_valid = 0;
	char_index = 0;
	character = *(arg + char_index);
	if (character == '-')
	{
		char_index ++;
		character = *(arg + char_index);
	}
	while (character)
	{
		is_valid = ft_isdigit(character);
		if (!is_valid)
			break ;
		char_index ++;
		character = *(arg + char_index);
	}
	return (is_valid);
}

int	ps_is_valid_input(const int argc, const char **argv)
{
	const char	*arg;
	int			is_valid;
	int			arg_index;

	is_valid = 0;
	arg_index = 1;
	while (arg_index < argc)
	{
		arg = *(argv + arg_index);
		is_valid = ps_is_numeric(arg);
		if (!is_valid)
			break ;
		is_valid = !ft_ioverflow(arg);
		if (!is_valid)
			break ;
		arg_index ++;
	}
	return (is_valid);
}
