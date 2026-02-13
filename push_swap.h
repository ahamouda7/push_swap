#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
    int				value;
    struct s_list	*next;
}   t_list;

size_t 	ft_strlen(char *str);
char 	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(char *str, int *valid);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s);
t_list  *ft_lstnew(int value);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstadd_front(t_list **lst, t_list *new);
void	swap(t_list **stack);
void	push(t_list **stack_1, t_list **stack_2);
void	rotate(t_list **stack);
void	rrotate(t_list **stack);

#endif