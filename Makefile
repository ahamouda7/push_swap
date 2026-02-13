NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_split.c ft_strcmp.c ft_strjoin.c ft_strlen.c \
		ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c swap.c \
		push.c rotate.c rrotate.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean