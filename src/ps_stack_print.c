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
#include <stdio.h>

void	ps_stack_print(t_list *head)
{
	long	*number;
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
		number = (long *) current_node->data;
		ft_printf("%l", *number);
		if (current_node->next_node)
			ft_printf(", ");
		current_node = current_node->next_node;
	}
	ft_printf("}\n");
}
