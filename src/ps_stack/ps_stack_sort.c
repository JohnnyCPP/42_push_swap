/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ps_stack_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (ps_stack_issorted(stack_a))
		return ;
	else if (size == 2)
		ps_instruction_sa(stack_a);
	else if (size == 3)
		ps_short_sort(stack_a, size);
	else if (size <= 7)
		ps_simple_insertion_sort(stack_a, stack_b, size);
	else if (size > 7)
		ps_k_sort(stack_a, stack_b, size);
}
