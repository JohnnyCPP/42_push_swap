/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_short_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ps_get_min_index(const t_stack *stack)
{
	const	t_node	*current_node;
	int				current_index;
	int				result;

	if (!stack || !stack->head)
		return (-1);
	current_node = stack->head;
	result = current_node->s_index;
	while (current_node)
	{
		current_index = current_node->s_index;
		if (current_index < result)
			result = current_index;
		current_node = current_node->next;
	}
	return (result);
}

int	ps_get_index_position(const t_node *head, const int index)
{
	const	t_node	*current_node;
	int				current_position;
	int				current_index;

	current_node = head;
	current_position = 0;
	while (current_node)
	{
		current_index = current_node->s_index;
		if (current_index == index)
			return (current_position);
		current_node = current_node->next;
		current_position ++;
	}
	return (-1);
}
