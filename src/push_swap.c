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
	int		is_valid;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	is_valid = ps_is_valid_input(argc, argv);
	if (!is_valid)
	{
		ps_print_error();
		return (1);
	}
	ft_printf("Valid input.\n");
	// initialize stack_a and stack_b
	stack_a = ps_init_stack_a(argc, argv);
	stack_b = ft_list_new(NULL);
	// develop a function to print a stack
	ft_printf("Stack_A:");
	ps_stack_print(stack_a);
	ft_printf("Stack_B:");
	ps_stack_print(stack_b);
	// develop functions to manipulate stacks
	// implement a radix_sort() function
	return (0);
}
