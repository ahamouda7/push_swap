/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:49:55 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/20 09:11:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*remove_spaces(char *str)
{
	int	end;

	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	end = 0;
	while (str[end])
		end++;
	end--;
	while (end > 0 && (str[end] == ' ' || str[end] == '\t'))
		end--;
	end++;
	str[end] = '\0';
	return (str);
}
