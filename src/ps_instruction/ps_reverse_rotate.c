/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ps_reverse_rotate(t_stack *stack)
{
	t_node	*next_node;
	t_node	*current_node;

	if (!stack->head || !stack->head->next)
		return ;
	current_node = stack->head;
	while (current_node->next->next)
		current_node = current_node->next;
	next_node = current_node->next;
	current_node->next = NULL;
	next_node->next = stack->head;
	stack->head = next_node;
}
