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

static	void	ps_print(t_list *stack_a, t_list *stack_b)
{
	ft_printf("Stack_A:");
	ps_stack_print(stack_a);
	ft_printf("Stack_B:");
	ps_stack_print(stack_b);
}

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
	stack_a = ps_init_stack_a(argc, argv);
	stack_b = NULL;
	is_valid = !ps_contains_duplicates(stack_a);
	if (!is_valid)
	{
		ps_print_error();
		return (1);
	}
	ps_print(stack_a, stack_b);
	ps_radix_sort(&stack_a, &stack_b);
	ps_print(stack_a, stack_b);
	ps_terminate_stack_a(&stack_a);
	return (0);
}
