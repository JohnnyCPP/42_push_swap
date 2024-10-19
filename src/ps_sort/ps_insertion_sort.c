/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ps_sisort_end(t_stack *s_a, t_stack *s_b, int s, int a_l)
{
	int	iterator;

	ps_short_sort(s_a, s);
	iterator = 0;
	while (iterator < a_l - 3)
	{
		ps_instruction_pa(s_b, s_a);
		iterator ++;
	}
}

static	void	ps_sisort_condition(int r_a, int r_b, int min_i, t_stack *s_a)
{
	if (r_a <= r_b)
		while (s_a->head->s_index != min_i)
			ps_instruction_ra(s_a);
	else
		while (s_a->head->s_index != min_i)
			ps_instruction_rra(s_a);
}

void	ps_simple_insertion_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	iterator;
	int	a_len;
	int	min_i;
	int	r_a;
	int	r_b;

	if (!stack_a || !stack_b)
		return ;
	iterator = 0;
	a_len = size;
	while (iterator < a_len - 3)
	{
		min_i = ps_get_min_index(stack_a);
		r_a = ps_get_index_position(stack_a->head, min_i);
		r_b = a_len - min_i - ps_get_index_position(stack_a->head, min_i);
		ps_sisort_condition(r_a, r_b, min_i, stack_a);
		if (ps_stack_issorted(stack_a) && stack_b->size == 0)
			return ;
		ps_instruction_pb(stack_a, stack_b);
		size --;
		iterator ++;
	}
	ps_sisort_end(stack_a, stack_b, size, a_len);
}

void	ps_insertion_sort(int *numbers, const int size)
{
	int	number;
	int	next;
	int	previous;

	next = 1;
	while (next < size)
	{
		number = numbers[next];
		previous = next - 1;
		while (previous >= 0 && numbers[previous] > number)
		{
			numbers[previous + 1] = numbers[previous];
			previous --;
		}
		numbers[previous + 1] = number;
		next ++;
	}
}
