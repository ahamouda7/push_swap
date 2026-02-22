/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:48:27 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:48:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rrotate(t_bs_list **stack)
{
	t_bs_list	*last;
	t_bs_list	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while ((prev->next)->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	ft_lstadd_front(stack, last);
}

void	rra(t_bs_list **stack_a)
{
	rrotate(stack_a);
}

void	rrb(t_bs_list **stack_b)
{
	rrotate(stack_b);
}

void	rrr(t_bs_list **stack_a, t_bs_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
}
