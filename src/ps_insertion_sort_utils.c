/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	int	ps_isort_is_greater(const int i_of_val, t_list **stack_a)
{
	t_list	*head;
	int		*last_value;
	int		*current_value;
	int		i_current_node;

	head = *stack_a;
	last_value = NULL;
	i_current_node = 0;
	while (head && i_current_node <= i_of_val)
	{
		if (last_value)
		{
			last_value = current_value;
			current_value = (int *) head->data;
		}
		else
		{
			current_value = (int *) head->data;
			last_value = current_value;
		}
		head = head->next_node;
		i_current_node ++;
	}
	if (*current_value > *last_value)
		return (1);
	return (0);
}

static	void	ps_isort_rev(int moves, t_list **stack_a, t_list **stack_b)
{
	int	*a_number;
	int	*b_number;
	int	reverse_moves;

	reverse_moves = 0;
	while (moves)
	{
		a_number = (int *) (*stack_a)->data;
		b_number = (int *) (*stack_b)->data;
		if (*b_number < *a_number)
		{
			ps_instruction_pa(stack_b, stack_a);
			break ;
		}
		ps_instruction_ra(stack_a);
		moves --;
		reverse_moves ++;
	}
	while (reverse_moves)
	{
		ps_instruction_rra(stack_a);
		reverse_moves --;
	}

}

void	ps_isort_sort(t_list **stack_a, t_list **stack_b, int position)
{
	int	is_greater;
	int	moves;

	is_greater = ps_isort_is_greater(position, stack_a);
	if (is_greater)
		return ;
	moves = 0;
	while (moves < position)
	{
		ps_instruction_ra(stack_a);
		moves ++;
	}
	ps_instruction_pb(stack_a, stack_b);
	moves = 0;
	while (moves < position)
	{
		ps_instruction_rra(stack_a);
		moves ++;
	}
	ps_isort_rev(moves, stack_a, stack_b);
}

void	ps_isort_sort_two(t_list **stack_a)
{
	int	*head_number;
	int	*second_number;

	head_number = (int *) (*stack_a)->data;
	second_number = (int *) (*stack_a)->next_node->data;
	if (*second_number < *head_number)
		ps_instruction_sa(stack_a);
}
