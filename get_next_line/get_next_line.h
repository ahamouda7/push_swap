#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

size_t		ft_strlen(char *str);
size_t		ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);

#endif