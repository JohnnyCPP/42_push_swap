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

int	main(const int argc, const char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		is_valid;
	int		numbers_amount;
	int		*numbers;

	if (argc < 2)
		return (0);
	is_valid = ps_is_valid_input(argc, argv);
	if (!is_valid)
		return (ps_print_error());
	numbers_amount = argc - 1;
	numbers = ps_args_to_numbers(argc, argv);
	is_valid = !ps_contains_duplicates(numbers, numbers_amount);
	if (!is_valid)
		return (ps_duplicated_numbers(numbers));
	ps_init_stacks(&stack_a, &stack_b, numbers, numbers_amount);
	ft_printf("Stack A: ");
	ps_stack_print(&stack_a);
	ft_printf("\n");
	ps_stack_sort(&stack_a, &stack_b, numbers_amount);
	ft_printf("Stack A: ");
	ps_stack_print(&stack_a);
	ft_printf("\n");
	ft_printf("Stack B: ");
	ps_stack_print(&stack_b);
	ft_printf("\n");
	ps_stack_clear(&stack_a);
	free(numbers);
	return (0);
}
