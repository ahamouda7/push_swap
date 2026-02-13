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

static int	isdup(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		j = i + 1;
		while(str[j])
		{
			if (!ft_strcmp(str[i], str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	**isvalid(char **argv, int *valid)
{
    char    *str;
	char	**nbrs_str;
	int		i;

	str = return_str(str, argv);
    if (!str)
        return (*valid = 0, NULL);
    nbrs_str = ft_split(str);
	if (isdup(nbrs_str))
		return (*valid = 0, NULL);
    i = 0;
    *valid = 1;
    while(nbrs_str[i])
    {
        ft_atoi(nbrs_str[i], valid);
		if (!valid)
			return (*valid = 0, NULL);
        i++;
    }
	return (nbrs_str);
}

int main(int argc, char **argv)
{
    char    **nbrs_str;
	t_list	*stack_a;
	t_list	*new;
    int     valid;
    int     i;

	valid = 1;
    nbrs_str = isvalid(argv, &valid);
	if (!valid)
		return(write(1, "Error\n", 6), 0);
	i = 0;
	stack_a = NULL;
	while(nbrs_str[i])
	{
		new = ft_lstnew(ft_atoi(nbrs_str[i], &valid));
		ft_lstadd_back(&stack_a, new);
		i++;
	}
}
