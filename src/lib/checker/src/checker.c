/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

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
	//	-> HOW TO ACCEPT INPUT FROM THE PIPE OF A PROGRAM
	//
	//	-> APPLY THE LOGIC, USING THE RECEIVED INPUT, TO MANIPULATE THE STACKS
	//
	//	-> FINALLY, VERIFY THE STACK_A IS SORTED AND STACK_B IS EMPTY
	ft_printf("Checker is working as expected.\n");
	ps_stack_clear(&stack_a);
	free(numbers);
	return (0);
}
