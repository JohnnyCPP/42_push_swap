/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ps_stack_push(t_stack *stack, const int index, const int data)
{
	t_node	*new_node;

	new_node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (new_node)
	{
		new_node->data = data;
		new_node->s_index = index;
		new_node->next = stack->head;
		stack->head = new_node;
		stack->size ++;
	}
}
