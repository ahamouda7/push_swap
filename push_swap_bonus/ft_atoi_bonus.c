/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:47:40 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:47:40 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_atoi(char *str, int *valid)
{
	long	res;
	int		sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (*str < '0' || *str > '9')
			return (*valid = 0, 0);
	}
	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (*valid = 0, 0);
		res = res * 10 + (*str - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (*valid = 0, 0);
		str++;
	}
	return ((int)(res * sign));
}
