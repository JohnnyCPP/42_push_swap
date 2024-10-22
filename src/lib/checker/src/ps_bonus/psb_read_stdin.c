/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_read_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	psb_read_stdin(t_stack *stack_a, t_stack *stack_b)
{
	char	*line_read;
	int		is_valid_instruction;

	line_read = ft_gnl(0);
	while (line_read && line_read[0])
	{
		is_valid_instruction = psb_is_instruction(line_read);
		if (!is_valid_instruction)
			return (psb_invalid_instruction(line_read));
		psb_instruct(line_read, stack_a, stack_b);
		free(line_read);
		line_read = ft_gnl(0);
	}
	return (0);
}
