#include "push_swap_bonus.h"

void	free_2d(char **arr)
{
    int i = 0;

	if (!arr)
		return ;
    while (arr[i])
	{
        free(arr[i]);
		i++;
	}
    free(arr);
}