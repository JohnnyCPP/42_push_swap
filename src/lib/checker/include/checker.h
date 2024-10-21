/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

/**
 * @brief Structure representing a node in a stack.
 *
 * This structure keeps track of its position in the stack, 
 * contains data as an integer value, and a pointer to a next node.
 */
typedef struct s_node
{
	int				data;
	int				s_index;
	struct s_node	*next;
}	t_node;

/**
 * @brief Structure representing a stack.
 *
 * This structure keeps track of its size, and contains 
 * a pointer to the first node of the stack, the head.
 */
typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

/**
 * @brief Prints "Error" followed by a newline character.
 *
 * @return Always returns 1, which is meant to be "ended with errors".
 */
int		ps_print_error(void);

/**
 * @brief Frees the list of numbers, and prints "Error".
 *
 * @param numbers The list of numbers to free.
 *
 * @return Always returns 1, which is returned by "ps_print_error()".
 *
 * This function frees the memory of the list of numbers and 
 * runs "ps_print_error()", displaying an error message and returning 
 * an error code.
 */
int		ps_duplicated_numbers(int *numbers);

/**
 * @brief Checks if the user input is correct.
 *
 * @param argc Arguments count, represents the amount (+1) of arguments passed 
 *             to the program. The program name is the first argument.
 * @param argv Arguments vector, a double pointer to the arguments passed 
 *             when the program is executed.
 *
 * @return 1 if the input is valid, 0 otherwise.
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
int		ps_is_valid_input(const int argc, const char **argv);

/**
 * @brief From an argument vector, create a list of numbers.
 *
 * @param argc Arguments count.
 * @param argv Arguments vector.
 *
 * @return A pointer to the first number in the list.
 */
int		*ps_args_to_numbers(const int argc, const char **argv);

/**
 * @brief Builds stack_a and stack_b, allocating memory for stack_a.
 *
 * @param s_a The stack_a which will be dynamically allocated.
 * @param s_b The stack_b which will be set to NULL.
 * @param nums A list of numbers to initialize stack_a with.
 * @param size The amount of numbers in the list of numbers.
 */
void	ps_init_stacks(t_stack *s_a, t_stack *s_b, int *nums, int size);

/**
 * @brief Starting from the head, deletes and frees all nodes of a stack.
 *
 * @param stack The stack to clear.
 *
 * This function iterates, calling "ps_stack_pop()", until 
 * the stack size is zero.
 */
void	ps_stack_clear(t_stack *stack);

/**
 * @brief Creates a new node and adds it to the head of a stack.
 *
 * @param stack The stack to add the new node to.
 * @param index The position in the stack for the new node.
 * @param data The number to add to the new node.
 *
 * This function dynamically allocates memory for a new node.
 */
void	ps_stack_push(t_stack *stack, const int index, const int data);

/**
 * @brief Deletes the first node of a stack, freeing its memory.
 *
 * @param stack The stack whose first node will be deleted and freed.
 */
void	ps_stack_pop(t_stack *stack);

/**
 * @brief Checks if a stack is sorted in ascending manner.
 *
 * @param stack The stack to check if it's sorted.
 *
 * @return 1 if the stack is sorted, 0 otherwise.
 */
int		ps_stack_issorted(const t_stack *stack);

/**
 * @brief Checks if a list of numbers contains two instances of a number.
 *
 * @param numbers A pointer to the first number of the list.
 * @param size The amount of numbers the list has.
 *
 * @return 1 if the list of numbers contains duplicates, 0 if not.
 *
 * This function iterates through each number of the list and, for each 
 * one, iterates through all the numbers counting how many times that 
 * number is present in it.
 */
int		ps_contains_duplicates(const int *numbers, const int size);

/**
 * @brief Changes the position of the two first elements of a stack.
 *
 * @param stack The stack whose first two elements will be swapped.
 *
 * This function accepts a pointer to a stack.
 *
 * Then obtains its first, second, and third elements.
 *
 * Then, makes so the first node points to the third, and the second node 
 * points to the first node.
 *
 * It does nothing if the stack contains less than two nodes. 
 */
void	ps_swap(t_stack *stack);

/**
 * @brief Swaps the first two elements of "stack_a".
 *
 * @param stack_a The stack to swap the first two elements to.
 *
 * This function calls "ps_swap" and prints "sa" in the standard output.
 */
void	ps_instruction_sa(t_stack *stack_a);

/**
 * @brief Swaps the first two elements of "stack_b".
 *
 * @param stack_b The stack to swap the first two elements to.
 *
 * This function calls "ps_swap" and prints "sb" in the standard output.
 */
void	ps_instruction_sb(t_stack *stack_b);

/**
 * @brief Swaps the first two elements of "stack_a" and "stack_b".
 *
 * @param stack_a A stack to swap the first two elements to.
 * @param stack_b A stack to swap the first two elements to.
 *
 * This function calls "ps_swap" twice and prints "ss" in the standard output.
 */
void	ps_instruction_ss(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Sets the first node of source as the first node of destination.
 *
 * @param source A pointer to the "source" stack.
 * @param destination A pointer to the "destination" stack.
 *
 * This function makes the head of stack "source" to point to the 
 * head of stack "destination".
 *
 * If the "destination" stack points to a NULL node, just the head of 
 * "source" becomes the head of "destination".
 */
void	ps_push(t_stack *source, t_stack *destination);

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
void	ps_instruction_pa(t_stack *stack_b, t_stack *stack_a);

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
void	ps_instruction_pb(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Displaces all the nodes of a stack by one place up.
 *
 * @param stack A pointer to a stack.
 *
 * This function moves up all the elements of a stack by one position, 
 * in a way that the first element becomes the last one.
 */
void	ps_rotate(t_stack *stack);

/**
 * @brief Displaces all the nodes of a stack by one place down.
 *
 * This function moves down all the elements of a stack by one position, 
 * in a way that the last element becomes the first one.
 */
void	ps_reverse_rotate(t_stack *stack);

/**
 * @brief Displaces all the nodes of "stack_a" by one place up.
 *
 * @param stack_a The stack whose nodes will be displaced.
 *
 * This function invokes "ps_rotate" function to rotate the nodes of 
 * the stack, and prints "ra" in the standard output.
 */
void	ps_instruction_ra(t_stack *stack_a);

/**
 * @brief Displaces all the nodes of "stack_b" by one place up.
 *
 * @param stack_b The stack whose nodes will be displaced.
 *
 * This function invokes "ps_rotate" function to rotate the nodes of 
 * the stack, and prints "rb" in the standard output.
 */
void	ps_instruction_rb(t_stack *stack_b);

/**
 * @brief Displaces all the nodes of "stack_a" and "stack_b" one place up.
 *
 * @param stack_a A stack whose nodes will be displaced.
 * @param stack_b A stack whose nodes will be displaced.
 *
 * This function runs "ps_rotate" to move the nodes of both stacks 
 * one place up.
 *
 * The first nodes of each stack become the last ones.
 */
void	ps_instruction_rr(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Displaces all the nodes of "stack_a" by one place down.
 *
 * @param stack_a The stack whose nodes will be displaced.
 *
 * This function invokes "ps_reverse_rotate" function to rotate the nodes of 
 * the stack, and prints "rra" in the standard output.
 */
void	ps_instruction_rra(t_stack *stack_a);

/**
 * @brief Displaces all the nodes of "stack_b" by one place down.
 *
 * @param stack_b The stack whose nodes will be displaced.
 *
 * This function invokes "ps_reverse_rotate" function to rotate the nodes of 
 * the stack, and prints "rrb" in the standard output.
 */
void	ps_instruction_rrb(t_stack *stack_b);

/**
 * @brief Displaces all the nodes of "stack_a" and "stack_b" one place down.
 *
 * @param stack_a A stack whose nodes will be displaced.
 * @param stack_b A stack whose nodes will be displaced.
 *
 * This function runs "ps_reverse_rotate" to move the nodes of 
 * both stacks one place down.
 */
void	ps_instruction_rrr(t_stack *stack_a, t_stack *stack_b);

#endif
