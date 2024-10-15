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
 * @brief Starting from the head, deletes all nodes from a linked list.
 *
 * @param head The first node of a linked list.
 *
 * This function makes use of a local function to free the data member
 * of each node, with the node itself.
 */
void	ps_terminate_stack_a(t_list **head);

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

/**
 * @brief Changes the position of the two first elements of a linked list.
 *
 * @param head The linked list whose first two elements will be swapped.
 *
 * This function accepts a double pointer to the head of a linked list.
 *
 * It dereferences it to obtain its first, second, and third elements.
 *
 * Then, makes so the first node points to the third, and the second node 
 * points to the first node.
 *
 * It does nothing if the double pointer is null, or if the linked list 
 * contains less than two nodes.
 */
void	ps_swap(t_list **head);

/**
 * @brief Swaps the first two elements of "stack_a".
 *
 * @param stack_a The stack to swap the first two elements to.
 *
 * This function calls "ps_swap" and prints "sa" in the standard output.
 */
void	ps_instruction_sa(t_list **stack_a);

/**
 * @brief Swaps the first two elements of "stack_b".
 *
 * @param stack_b The stack to swap the first two elements to.
 *
 * This function calls "ps_swap" and prints "sb" in the standard output.
 */
void	ps_instruction_sb(t_list **stack_b);

/**
 * @brief Swaps the first two elements of "stack_a" and "stack_b".
 *
 * @param stack_a A stack to swap the first two elements to.
 * @param stack_b A stack to swap the first two elements to.
 *
 * This function calls "ps_swap" twice and prints "ss" in the standard output.
 */
void	ps_instruction_ss(t_list **stack_a, t_list **stack_b);

/**
 * @brief Sets the first node of source as the first node of destination.
 *
 * @param source A double pointer to the head of stack "source".
 * @param destination A double pointer to the head of stack "destination".
 *
 * This function makes the head of stack "source" to point to the 
 * head of stack "destination".
 *
 * Then, the second node of stack "source" becomes its head, and the 
 * old head of stack "source" becomes the head of stack "destination".
 *
 * If the stack "destination" points to a NULL node, just the head of stack 
 * "source" becomes the "head" of stack "destination".
 */
void	ps_push(t_list **source, t_list **destination);

/**
 * @brief Moves the head of "stack_b", to be the head of "stack_a".
 *
 * @param stack_b The stack whose head will be moved.
 * @param stack_a The stack to which the head will be placed to.
 *
 * This function moves the first node of the "stack_b" and adds it 
 * as the first node of "stack_a". Then, the second node of "stack_b" 
 * becomes the first one.
 */
void	ps_instruction_pa(t_list **stack_b, t_list **stack_a);

/**
 * @brief Moves the head of "stack_a", to be the head of "stack_b".
 *
 * @param stack_a The stack whose head will be moved.
 * @param stack_b The stack to which the head will be placed to.
 *
 * This function moves the first node of the "stack_a" and adds it 
 * as the first node of "stack_b". Then, the second node of "stack_a" 
 * becomes the first one.
 */
void	ps_instruction_pb(t_list **stack_a, t_list **stack_b);

/**
 * @brief Displaces all the nodes of a linked list by one place up.
 *
 * @param head A double pointer to the head of the linked list.
 *
 * This function moves up all the elements of a linked list by one position, 
 * in a way that the first element becomes the last one of the linked list.
 */
void	ps_rotate(t_list **head);

/**
 * @brief Displaces all the nodes of a linked list by one place down.
 *
 * This function moves down all the elements of a linked list by one position, 
 * in a way that the last element becomes the first one of the linked list
 */
void	ps_reverse_rotate(t_list **head);

/**
 * @brief Displaces all the nodes of "stack_a" by one place up.
 *
 * @param stack_a The linked list whose nodes will be displaced.
 *
 * This function invokes "ps_rotate" function to rotate the nodes of 
 * the linked list, and prints "ra" in the standard output.
 */
void	ps_instruction_ra(t_list **stack_a);

/**
 * @brief Displaces all the nodes of "stack_b" by one place up.
 *
 * @param stack_b The linked list whose nodes will be displaced.
 *
 * This function invokes "ps_rotate" function to rotate the nodes of 
 * the linked list, and prints "rb" in the standard output.
 */
void	ps_instruction_rb(t_list **stack_b);

/**
 * @brief Displaces all the nodes of "stack_a" and "stack_b" one place up.
 *
 * @param stack_a A linked list whose nodes will be displaced.
 * @param stack_b A linked list whose nodes will be displaced.
 *
 * This function runs "ps_rotate" to move the nodes of both linked lists 
 * one place up.
 *
 * The first nodes of each linked list become the last ones.
 */
void	ps_instruction_rr(t_list **stack_a, t_list **stack_b);

/**
 * @brief Displaces all the nodes of "stack_a" by one place down.
 *
 * @param stack_a The linked list whose nodes will be displaced.
 *
 * This function invokes "ps_reverse_rotate" function to rotate the nodes of 
 * the linked list, and prints "rra" in the standard output.
 */
void	ps_instruction_rra(t_list **stack_a);

/**
 * @brief Displaces all the nodes of "stack_b" by one place down.
 *
 * @param stack_b The linked list whose nodes will be displaced.
 *
 * This function invokes "ps_reverse_rotate" function to rotate the nodes of 
 * the linked list, and prints "rrb" in the standard output.
 */
void	ps_instruction_rrb(t_list **stack_b);

/**
 * @brief Displaces all the nodes of "stack_a" and "stack_b" one place down.
 *
 * @param stack_a A linked list whose nodes will be displaced.
 * @param stack_b A linked list whose nodes will be displaced.
 *
 * This function runs "ps_reverse_rotate" to move the nodes of 
 * both linked lists one place down.
 */
void	ps_instruction_rrr(t_list **stack_a, t_list **stack_b);

/**
 *
 */
void	ps_radix_sort(t_list **stack_a, t_list **stack_b);

#endif
