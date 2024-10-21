/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_k_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ps_k_sort_second(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	end_position;
	int	position;

	while (size - 1 >= 0)
	{
		end_position = ps_get_index_position(stack_b->head, size - 1);
		position = (size + 3) - end_position;
		if (end_position <= position)
		{
			while (stack_b->head->s_index != size - 1)
				ps_instruction_rb(stack_b);
			ps_instruction_pa(stack_b, stack_a);
			size --;
		}
		else
		{
			while (stack_b->head->s_index != size - 1)
				ps_instruction_rrb(stack_b);
			ps_instruction_pa(stack_b, stack_a);
			size --;
		}
	}
}

static	void	ps_k_sort_first(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	iterator;
	int	range;
	int	i_of_a;

	iterator = 0;
	range = ft_sqrt(size) * 14 / 10;
	while (stack_a->head)
	{
		i_of_a = stack_a->head->s_index;
		if (i_of_a <= iterator)
		{
			ps_instruction_pb(stack_a, stack_b);
			ps_instruction_rb(stack_b);
			iterator ++;
		}
		else if (i_of_a <= iterator + range)
		{
			ps_instruction_pb(stack_a, stack_b);
			iterator ++;
		}
		else
			ps_instruction_ra(stack_a);
	}
}

void	ps_k_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	ps_k_sort_first(stack_a, stack_b, size);
	ps_k_sort_second(stack_a, stack_b, size);
}
