#include "push_swap.h"

static size_t ft_strlen(char *str)
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char *ft_strjoin(char *s1, char *s2)
{
	char *s;
	size_t i;
	size_t len1;
	size_t len2;

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

char    *return_str(char *str, char **argv)
{
    int i;
    int j;

    i = 1;
    while(argv[i])
    {
        j = 0;
        if (!*argv[i])
            return (NULL);
        while(argv[i][j] && (argv[i][j] == ' ' || argv[i][j] == '\t'))
            j++;
        if (!argv[i][j])
            return (NULL);
        str = ft_strjoin(str, &argv[i][j]);
        if (argv[i + 1])
            str = ft_strjoin(str, " ");
        i++;
    }
    return str;
}

static int	ft_atoi(char *str, int *valid)
{
    int res;
    int sign;

    sign = 1;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while(*str)
    {
        if (*str < '0' || *str > '9')
        {
            *valid = 0;
            return (0);
        }
        res = res * 10 + (*str - '0');
        str++;
    }
    if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
    {
        *valid = 0;
        return (0);
    }
    return (res * sign);
}
// #include <stdio.h>
int main(int argc, char **argv)
{
    char    *str;
    char    **nbrs_str;
    int		**nbrs;
    int     valid;
    int     nb;
    int     i;

    // str = NULL;
    str = return_str(str, argv);
    if (!str)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    // printf("%s\n", str);
    nbrs_str = ft_split(str);
    i = 0;
    valid = 1;
    while(nbrs_str[i])
    {
        nb = ft_atoi(nbrs_str[i], &valid);
		if (!valid)
		{
			write(1, "Error\n", 6);
        	return (0);
		}
        i++;
    }
}