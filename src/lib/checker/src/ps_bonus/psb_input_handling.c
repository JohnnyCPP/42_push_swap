/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_input_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	psb_invalid_instruction(char *line_read)
{
	free(line_read);
	return (ps_print_error());
}

int	psb_is_instruction(char *line_read)
{
	if (!line_read)
		return (0);
	if (!ft_strcmp(line_read, "pa\n"))
		return (1);
	else if (!ft_strcmp(line_read, "pb\n"))
		return (1);
	else if (!ft_strcmp(line_read, "ra\n"))
		return (1);
	else if (!ft_strcmp(line_read, "rb\n"))
		return (1);
	else if (!ft_strcmp(line_read, "rr\n"))
		return (1);
	else if (!ft_strcmp(line_read, "rra\n"))
		return (1);
	else if (!ft_strcmp(line_read, "rrb\n"))
		return (1);
	else if (!ft_strcmp(line_read, "rrr\n"))
		return (1);
	else if (!ft_strcmp(line_read, "sa\n"))
		return (1);
	else if (!ft_strcmp(line_read, "sb\n"))
		return (1);
	else if (!ft_strcmp(line_read, "ss\n"))
		return (1);
	return (0);
}

void	psb_instruct(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (!instruction)
		return ;
	if (!ft_strcmp(instruction, "pa\n"))
		ps_push(stack_b, stack_a);
	else if (!ft_strcmp(instruction, "pb\n"))
		ps_push(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "ra\n"))
		ps_rotate(stack_a);
	else if (!ft_strcmp(instruction, "rb\n"))
		ps_rotate(stack_b);
	else if (!ft_strcmp(instruction, "rr\n"))
		psb_rr(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "rra\n"))
		ps_reverse_rotate(stack_a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		ps_reverse_rotate(stack_b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		psb_rrr(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "sa\n"))
		ps_swap(stack_a);
	else if (!ft_strcmp(instruction, "sb\n"))
		ps_swap(stack_b);
	else if (!ft_strcmp(instruction, "ss\n"))
		psb_ss(stack_a, stack_b);
}
