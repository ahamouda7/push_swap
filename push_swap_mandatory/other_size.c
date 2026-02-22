/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:49:42 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/22 09:06:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_with_range(t_list **stack_a, t_list **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

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
	int	range;

	if (ft_lstsize(*stack_a) <= 100)
		range = 15;
	else
		range = ft_lstsize(*stack_a) / 13;
	push_with_range(stack_a, stack_b, range);
	push_back(stack_a, stack_b);
}
