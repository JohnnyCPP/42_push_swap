/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		is_valid;
	int		threshold;

	if (argc < 2)
		return (0);
	is_valid = ps_is_valid_input(argc, argv);
	threshold = 50;
	if (!is_valid)
		return (ps_print_error());
	stack_a = ps_init_stack_a(argc, argv);
	stack_b = NULL;
	is_valid = !ps_contains_duplicates(stack_a);
	if (!is_valid)
	{
		ps_terminate_stack_a(&stack_a);
		return (ps_print_error());
	}
	if (argc > 2 && argc <= (threshold + 1))
		ps_insertion_sort(&stack_a, &stack_b);
	else
		ps_radix_sort(&stack_a, &stack_b);
	ps_terminate_stack_a(&stack_a);
	return (0);
}
