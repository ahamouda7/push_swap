/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:48:19 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:48:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_bs_list **stack_1, t_bs_list **stack_2)
{
	t_bs_list	*first;

	first = *stack_1;
	*stack_1 = first->next;
	ft_lstadd_front(stack_2, first);
}

void	pa(t_bs_list **stack_b, t_bs_list **stack_a)
{
	push(stack_b, stack_a);
}

void	pb(t_bs_list **stack_a, t_bs_list **stack_b)
{
	push(stack_a, stack_b);
}
