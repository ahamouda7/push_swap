NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c ft_atoi.c ft_split.c ft_strjoin.c ft_strlen.c \
		ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstclear.c set_index.c operations.c which_size.c

BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean

$(OBJS): push_swap.h
$(BONUS_OBJS): push_swap_bonus.h