/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:48:30 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:48:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	set_index(t_bs_list *stack_a)
{
	t_bs_list	*i;
	t_bs_list	*j;

	i = stack_a;
	while (i)
	{
		i->index = 0;
		j = stack_a;
		while (j)
		{
			if (j->value < i->value)
				(i->index)++;
			j = j->next;
		}
		i = i->next;
	}
}
