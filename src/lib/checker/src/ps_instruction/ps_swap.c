/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	ps_swap(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;

	if (!stack->head || !stack->head->next)
		return ;
	first_node = stack->head;
	second_node = stack->head->next;
	third_node = second_node->next;
	stack->head = second_node;
	first_node->next = third_node;
	second_node->next = first_node;
}
