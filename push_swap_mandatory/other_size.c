/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:49:42 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:49:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_list *stack_b)
{
	int	max_index;

	max_index = stack_b->index;
	while (stack_b)
	{
		if (stack_b->index > max_index)
			max_index = stack_b->index;
		stack_b = stack_b->next;
	}
	return (max_index);
}

static int	order(t_list *stack_b, t_list *max)
{
	int	order;

	order = 0;
	while (stack_b)
	{
		if (max == stack_b)
			return (order);
		order++;
		stack_b = stack_b->next;
	}
	return (-1);
}

static void	push_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*may_max;

	set_index(*stack_b);
	may_max = *stack_b;
	while (*stack_b)
	{
		if (may_max->index == find_max(*stack_b))
		{
			if (order(*stack_b, may_max) < ft_lstsize(*stack_b) / 2)
			{
				while (may_max != *stack_b)
					rb(stack_b);
			}
			else
			{
				while (may_max != *stack_b)
					rrb(stack_b);
			}
			pa(stack_b, stack_a);
			set_index(*stack_b);
			may_max = *stack_b;
		}
		else
			may_max = may_max->next;
	}
}

void	other_size(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
		pb(stack_a, stack_b);
	push_back(stack_a, stack_b);
}
