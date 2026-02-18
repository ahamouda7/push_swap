/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:48:24 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:48:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_bs_list **stack)
{
	t_bs_list	*first;

	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

void	ra(t_bs_list **stack_a)
{
	rotate(stack_a);
}

void	rb(t_bs_list **stack_b)
{
	rotate(stack_b);
}

void	rr(t_bs_list **stack_a, t_bs_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
