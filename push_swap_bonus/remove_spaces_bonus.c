/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:48:22 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/21 17:45:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
