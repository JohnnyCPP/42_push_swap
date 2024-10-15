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
#include "push_swap.h"

void	ps_rotate(t_list **head)
{
	t_list	*second_node;
	t_list	*current_node;

	if (!head || !*head || !(*head)->next_node)
		return ;
	second_node = (*head)->next_node;
	current_node = *head;
	while ((current_node)->next_node)
		current_node = current_node->next_node;
	(*head)->next_node = NULL;
	current_node->next_node = *head;
	*head = second_node;
}
