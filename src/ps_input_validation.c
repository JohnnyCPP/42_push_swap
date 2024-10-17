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

static	int	ps_is_duplicated(long *number, t_list *head)
{
	int		times_spotted;
	long	*current_number;

	times_spotted = 0;
	while (head)
	{
		current_number = (long *) head->data;
		if (*current_number == *number)
			times_spotted ++;
		if (times_spotted > 1)
			return (1);
		head = head->next_node;
	}
	return (0);
}

int	ps_contains_duplicates(t_list *head)
{
	t_list	*current_node;
	long	*number;
	int		is_duplicated;

	current_node = head;
	while (current_node)
	{
		number = (long *) current_node->data;
		is_duplicated = ps_is_duplicated(number, head);
		if (is_duplicated)
			return (1);
		current_node = current_node->next_node;
	}
	return (0);
}

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
			break ;
		arg_index ++;
	}
	return (is_valid);
}
