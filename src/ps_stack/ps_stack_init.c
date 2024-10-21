/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	int	ps_get_index(const int number, const int *numbers, const int size)
{
	int	current;

	if (!numbers)
		return (-1);
	current = 0;
	while (current < size)
	{
		if (numbers[current] == number)
			return (current);
		current ++;
	}
	return (-1);
}

void	ps_init_stacks(t_stack *s_a, t_stack *s_b, int *nums, int size)
{
	int		current_num;
	t_node	*current_node;

	s_a->head = NULL;
	s_a->size = 0;
	s_b->head = NULL;
	s_b->size = 0;
	current_num = size - 1;
	while (current_num >= 0)
	{
		ps_stack_push(s_a, 0, nums[current_num]);
		current_num --;
	}
	ps_insertion_sort(nums, size);
	current_node = s_a->head;
	while (current_node)
	{
		current_node->s_index = ps_get_index(current_node->data, nums, size);
		current_node = current_node->next;
	}
}
