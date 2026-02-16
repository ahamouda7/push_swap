#include "push_swap_bonus.h"

char	*remove_spaces(char *str)
{
	int end;

	while(*str && (*str == ' ' || *str == '\t'))
		str++;
	end = 0;
	while(str[end])
		end++;
	while(end > 0 && (str[end] == ' ' || str[end] == '\t'))
		end--;
	str[end] = '\0';
	return (str);
}