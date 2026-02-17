#include "push_swap_bonus.h"

t_bs_list	*ft_lstnew(int value)
{
	t_bs_list	*newnode;

	newnode = malloc(sizeof(t_bs_list));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}
