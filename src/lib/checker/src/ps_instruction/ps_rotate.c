/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	ps_rotate(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*current_node;

	if (!stack->head || !stack->head->next)
		return ;
	first_node = stack->head;
	second_node = first_node->next;
	stack->head = second_node;
	current_node = first_node;
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = first_node;
	first_node->next = NULL;
}
