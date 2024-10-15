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

void	ps_radix_sort(t_list **stack_a, t_list **stack_b)
{
	// TODO: implement a radix_sort function
	//
	// I need to work with binary representations, so I need to develop 
	// a function that accepts a "long" and returns the binary representation 
	// of a number as a string
	//
	// I need a function that accepts a "long" and returns the specific bit 
	// of that value as an integer
	char	*binary_value;

	(void) stack_a;
	(void) stack_b;
	binary_value = ft_to_binary(2);
	char	*ptr_to_b = ft_split_binary_copy(binary_value);
	ft_printf("Binary:\"%s\"\n", ptr_to_b);
	free(binary_value);
	free(ptr_to_b);
}
