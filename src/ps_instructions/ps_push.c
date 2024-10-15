/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ps_push_to_non_null(t_list **source, t_list **destination)
{
	t_list	*src_next;

	src_next = (*source)->next_node;
	(*source)->next_node = (*destination);
	(*destination) = (*source);
	(*source) = src_next;
}

static	void	ps_push_to_null(t_list **source, t_list **destination)
{
	t_list	*src_next;

	src_next = (*source)->next_node;
	(*source)->next_node = NULL;
	(*destination) = (*source);
	(*source) = src_next;
}

void	ps_push(t_list **source, t_list **destination)
{
	if (!source || !destination || !*source || !(*source)->data)
		return ;
	if (!*destination)
		ps_push_to_null(source, destination);
	else
		ps_push_to_non_null(source, destination);
}
