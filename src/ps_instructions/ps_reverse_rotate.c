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

void	ps_reverse_rotate(t_list **head)
{
	t_list	*current_node;
	t_list	*last_item;

	if (!head || !*head || !(*head)->next_node)
		return ;
	current_node = *head;
	while (current_node->next_node->next_node)
		current_node = current_node->next_node;
	last_item = current_node->next_node;
	current_node->next_node = NULL;
	last_item->next_node = *head;
	*head = last_item;
}
