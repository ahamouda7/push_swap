/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:48:57 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:48:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strchr(const char *s, int c)
{
	char	target;

	if (!s)
		return (0);
	target = (char)c;
	while (*s)
	{
		if (*s == target)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc(len1 + len2 + 1);
	if (!s)
		return (free(s1), NULL);
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		s[i] = s2[i - len1];
		i++;
	}
	s[i] = '\0';
	return (free(s1), s);
}
