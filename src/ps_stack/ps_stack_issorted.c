/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_issorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ps_stack_issorted(const t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = stack->head;
	next_node = current_node->next;
	while (next_node)
	{
		if (current_node->data > next_node->data)
			return (0);
		current_node = current_node->next;
		next_node = current_node->next;
	}
	return (1);
}
