#include "push_swap_bonus.h"

void	ft_lstclear(t_bs_list **lst)
{
	t_bs_list	*current;
	t_bs_list	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
