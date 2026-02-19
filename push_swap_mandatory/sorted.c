/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:54:42 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/19 12:54:54 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > (stack_a->next)->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
