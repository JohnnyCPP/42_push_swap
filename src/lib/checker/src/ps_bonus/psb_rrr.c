/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	psb_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ps_reverse_rotate(stack_a);
	ps_reverse_rotate(stack_b);
}
