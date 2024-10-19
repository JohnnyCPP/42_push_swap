/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ps_push(t_stack *source, t_stack *destination)
{
	int	source_index;
	int	source_data;

	if (source->head)
	{
		source_index = source->head->s_index;
		source_data = source->head->data;
		ps_stack_pop(source);
		ps_stack_push(destination, source_index, source_data);
	}
}
