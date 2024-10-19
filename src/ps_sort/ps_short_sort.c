/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	int	ps_is_rotated_sorted(const t_stack *stack)
{
	const t_node	*first;
	const t_node	*second;
	const t_node	*third;

	if (!stack)
		return (0);
	if (!stack->head || !stack->head->next || !stack->head->next->next)
		return (0);
	first = stack->head;
	second = first->next;
	third = second->next;
	if (first->data < second->data && second->data < third->data)
		return (1);
	if (second->data < third->data && third->data < first->data)
		return (1);
	if (third->data < first->data && first->data < second->data)
		return (1);
	return (0);
}

void	ps_short_sort(t_stack *stack_a, const int size)
{
	int				min_index;
	int				position;

	if (!stack_a)
		return ;
	min_index = ps_get_min_index(stack_a);
	position = ps_get_index_position(stack_a->head, min_index);
	if (ps_is_rotated_sorted(stack_a))
	{
		if (position < size - position)
			ps_instruction_ra(stack_a);
		else
			ps_instruction_rra(stack_a);
	}
	else
	{
		ps_instruction_sa(stack_a);
		if (ps_stack_issorted(stack_a))
			return ;
		if (position < size - position)
			ps_instruction_ra(stack_a);
		else
			ps_instruction_rra(stack_a);
	}
}
