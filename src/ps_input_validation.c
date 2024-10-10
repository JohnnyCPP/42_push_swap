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

static	int	ps_is_numeric(char *arg)
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

int	ps_is_valid_input(int argc, char **argv)
{
	int		is_valid;
	int		arg_index;
	char	*arg;

	is_valid = 0;
	arg_index = 1;
	while (arg_index < argc)
	{
		arg = *(argv + arg_index);
		is_valid = ps_is_numeric(arg);
		if (!is_valid)
			break ;
		is_valid = !ft_loverflow(arg);
		if (!is_valid)
			break;
		arg_index ++;
	}
	return (is_valid);
}
