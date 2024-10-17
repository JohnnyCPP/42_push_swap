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

void	ps_insertion_sort(t_list **stack_a, t_list **stack_b)
{
	int		a_length;
	int		position;

	ps_isort_sort_two(stack_a);
	a_length = ft_list_size(*stack_a);
	position = 2;
	while (a_length > 2)
	{
		ps_isort_sort(stack_a, stack_b, position);
		a_length --;
		position ++;
	}
}
