/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	free_number(void *number)
{
	free((int *) number);
}

void	ps_terminate_stack_a(t_list **head)
{
	ft_list_clear(head, free_number);
}

t_list	*ps_init_stack_a(int argc, char **argv)
{
	t_list	*new_node;
	t_list	*last_node;
	char	*arg;
	int		arg_index;
	int		*number;

	arg_index = argc - 1;
	last_node = NULL;
	while (arg_index > 0)
	{
		arg = *(argv + arg_index);
		number = (int *) ft_calloc(1, sizeof(int));
		if (!number)
		{
			ps_terminate_stack_a(&last_node);
			return (NULL);
		}
		*number = ft_atoi(arg);
		new_node = ft_list_new(number);
		if (last_node)
			new_node->next_node = last_node;
		last_node = new_node;
		arg_index --;
	}
	return (last_node);
}
