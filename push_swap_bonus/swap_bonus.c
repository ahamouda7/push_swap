/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:48:36 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:48:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(t_bs_list **stack)
{
	t_bs_list	*first;
	t_bs_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_bs_list **stack_a)
{
	swap(stack_a);
}

void	sb(t_bs_list **stack_b)
{
	swap(stack_b);
}

void	ss(t_bs_list **stack_a, t_bs_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
