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
#include "push_swap.h"

void	ps_swap(t_list **head)
{
	t_list	*second_node;
	t_list	*third_node;

	if (!head || !*head || !(*head)->next_node)
		return ;
	second_node = (*head)->next_node;
	third_node = second_node->next_node;
	(*head)->next_node = third_node;
	second_node->next_node = *head;
	*head = second_node;
}
