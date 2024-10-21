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
#include "checker.h"

void	ps_stack_print(t_stack *stack)
{
	t_node	*current_node;
	int		number;

	if (!stack)
		ft_printf("NULL");
	else if (!stack->head)
		ft_printf("{NULL}");
	else
	{
		current_node = stack->head;
		ft_printf("{");
		while (current_node)
		{
			number = current_node->data;
			ft_printf("%i", number);
			current_node = current_node->next;
			if (current_node)
				ft_printf(", ");
		}
		ft_printf("}");
	}
}
