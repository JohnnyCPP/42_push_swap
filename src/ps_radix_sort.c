/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ps_merge(t_list **stack_b, t_list **stack_a)
{
	while (*stack_b)
		ps_instruction_pa(stack_b, stack_a);
}

static	void	ps_arrange(t_list **stack_a, t_list **stack_b, int *sig, int b)
{
	long	*number;
	int		a_length;
	int		bit;

	a_length = ft_list_size(*stack_a);
	while (a_length)
	{
		number = (long *) (*stack_a)->data;
		bit = ft_get_bit(*number, *sig);
		if (bit == b)
			ps_instruction_ra(stack_a);
		else
			ps_instruction_pb(stack_a, stack_b);
		a_length --;
	}
	(*sig)++;
}

static	void	ps_arrange_and_merge(t_list **s_a, t_list **s_b, int *s, int b)
{
	ps_arrange(s_a, s_b, s, b);
	ps_merge(s_b, s_a);
}

void	ps_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		significance;

	significance = 0;
	while (significance < BITS_IN_LONG - 1)
		ps_arrange_and_merge(stack_a, stack_b, &significance, 1);
	ps_arrange_and_merge(stack_a, stack_b, &significance, 0);
}
