/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_check_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	psb_check_result(t_stack *stack_a, t_stack *stack_b)
{
	if (ps_stack_issorted(stack_a) && !stack_b->size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
