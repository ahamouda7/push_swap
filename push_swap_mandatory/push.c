/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:49:52 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:49:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;

	if (!*stack_a)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	ft_lstadd_front(stack_b, first);
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
