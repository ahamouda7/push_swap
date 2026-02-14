#include "push_swap.h"

static char	*remove_spaces(char *str)
{
	int i;

	while(*str && (*str == ' ' || *str == '\t'))
		str++;
	i = 0;
	while(str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	str[i] = '\0';
	return (str);
}

static char	*return_str(char *str, char **argv)
{
    int i;
    int j;

    i = 1;
	str = NULL;
    while(argv[i])
    {
        j = 0;
        if (!*argv[i])
            return (NULL);
        argv[i] = remove_spaces(argv[i]);
		if (!argv[i][j]
			|| ((argv[i][j] == '-' || argv[i][j] == '+') && !argv[i][j + 1]))
            return (NULL);
        str = ft_strjoin(str, argv[i]);
        if (argv[i + 1])
            str = ft_strjoin(str, "_");
        i++;
    }
    return (str);
}

static int	isdup(t_list *stack_a)
{
	t_list	*i;
	t_list	*j;

	i = stack_a;
	while(i)
	{
		j = i->next;
		while(j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

static char	**isvalid(char **argv, int *valid)
{
    char    *str;
	char	**nbrs_strs;
	int		i;

	str = return_str(str, argv);
    if (!str)
        return (*valid = 0, NULL);
    nbrs_strs = ft_split(str);
    i = 0;
    *valid = 1;
    while(nbrs_strs[i])
    {
        ft_atoi(nbrs_strs[i], valid);
		if (!valid)
			return (*valid = 0, NULL);
        i++;
    }
	return (nbrs_strs);
}

static t_list	*do_stack_a(t_list **stack_a, char **nbrs_strs)
{
	int		i;
	t_list	*new;

	i = 0;
	while(nbrs_strs[i])
	{
		new = ft_lstnew(ft_atoi(nbrs_strs[i], &i));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (*stack_a);
}

int main(int argc, char **argv)
{
    char    **nbrs_strs;
	t_list	*stack_a;
    int     valid;

	valid = 1;
    nbrs_strs = isvalid(argv, &valid);
	if (!valid)
		return(write(2, "Error\n", 6), 0);
	stack_a = NULL;
	stack_a = do_stack_a(&stack_a, nbrs_strs);
	if (isdup(stack_a))
		return(write(2, "Error\n", 6), 0);
}
// #include <stdio.h>
// void	print_stack(t_list *stack)
// {
// 	while(stack)
// 	{
// 		printf("%d ", stack->value);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }