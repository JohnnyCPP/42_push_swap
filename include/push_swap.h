/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/**
 * @brief Prints "Error" followed by a newline character.
 */
void	ps_print_error(void);

/**
 * @brief Checks if the user input is correct.
 *
 * @param argc Arguments count, represents the amount (+1) of arguments passed 
 *             to the program. The program name is the first argument.
 * @param argv Arguments vector, a double pointer to the arguments passed 
 *             when the program is executed.
 *
 * This function checks if the arguments passed to the program are numbers, 
 * positive or negative.
 *
 * It accepts the minus '-' sign for negative numbers, but positive numbers 
 * with a plus '+' sign are rejected: positive numbers can't have a plus sign.
 *
 * If the arguments are numbers, it checks that they can be stored as 
 * variables of type long.
 */
int		ps_is_valid_input(int argc, char **argv);

/**
 * @brief Builds and allocates "stack_a" from a list of numbers.
 *
 * @param argc Arguments count, represents the amount (+1) of arguments.
 * @param argv Arguments vector, a double pointer to the arguments.
 *
 * @return A pointer to the head of "stack_a".
 *
 * This function builds, from a list of numbers (argv), a stack and returns it.
 *
 * It assumes that "argv" is a list of valid numbers.
 *
 * Uses "argc" to reversely iterate the list of numbers, where the head 
 * of the stack contains the first number passed to the program.
 *
 * Each node in the linked list is dynamically allocated.
 */
t_list	*ps_init_stack_a(int argc, char **argv);

/**
 * @brief Formats and displays the content of a linked list.
 *
 * @param head The first node of the linked list.
 *
 * This function prints the contents of a linked list, comma separated, 
 * and between curly braces.
 *
 * If the "head" node is null, it doesn't do anything.
 */
void	ps_stack_print(t_list *head);

/**
 * @brief Checks if a linked list contains two instances of the same number.
 *
 * @param head The first node of the linked list.
 *
 * @return 1 if the linked list contains duplicates, 0 if not.
 *
 * This function iterates through each node of the linked list and, for each 
 * value, iterates through all the elements counting how many times that 
 * value is present in the linked list.
 */
int		ps_contains_duplicates(t_list *head);

#endif
