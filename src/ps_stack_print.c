/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ps_stack_pb(const int number)
{
	char	*binary_number;

	binary_number = ft_to_binary_int(number);
	if (ft_split_binary_free(&binary_number))
	{
		ft_printf("%s", binary_number);
	}
	free(binary_number);
}

void	ps_stack_print_binary(t_list *head)
{
	int		*number;
	t_list	*current_node;

	if (!head || !head->data)
	{
		ft_printf("{NULL}\n");
		return ;
	}
	current_node = head;
	ft_printf("{\n");
	while (current_node)
	{
		number = (int *) current_node->data;
		if (number)
			ps_stack_pb(*number);
		else
			ft_printf("NULL");
		if (current_node->next_node)
			ft_printf(", \n");
		else
			ft_printf("\n");
		current_node = current_node->next_node;
	}
	ft_printf("}\n");
}

void	ps_stack_print(t_list *head)
{
	int		*number;
	t_list	*current_node;

	if (!head || !head->data)
	{
		ft_printf("{NULL}\n");
		return ;
	}
	current_node = head;
	ft_printf("{");
	while (current_node)
	{
		number = (int *) current_node->data;
		if (number)
			ft_printf("%i", *number);
		else
			ft_printf("NULL");
		if (current_node->next_node)
			ft_printf(", ");
		current_node = current_node->next_node;
	}
	ft_printf("}\n");
}
