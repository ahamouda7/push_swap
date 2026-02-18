CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

MANDATORY_DIR = push_swap_mandatory/
BONUS_DIR = push_swap_bonus/
GNL_DIR = get_next_line/

SRCS = $(MANDATORY_DIR)free_2d.c \
        $(MANDATORY_DIR)ft_atoi.c \
        $(MANDATORY_DIR)ft_lstadd_back.c \
        $(MANDATORY_DIR)ft_lstadd_front.c \
        $(MANDATORY_DIR)ft_lstclear.c \
        $(MANDATORY_DIR)ft_lstnew.c \
        $(MANDATORY_DIR)ft_lstsize.c \
        $(MANDATORY_DIR)ft_split.c \
        $(MANDATORY_DIR)ft_strjoin.c \
        $(MANDATORY_DIR)ft_strlen.c \
		$(MANDATORY_DIR)isdup.c \
		$(MANDATORY_DIR)swap.c \
		$(MANDATORY_DIR)push.c \
		$(MANDATORY_DIR)rotate.c \
		$(MANDATORY_DIR)rrotate.c \
		$(MANDATORY_DIR)other_size.c \
		$(MANDATORY_DIR)push_swap.c \
		$(MANDATORY_DIR)remove_spaces.c \
		$(MANDATORY_DIR)set_index.c \
		$(MANDATORY_DIR)small_size.c

BONUS_SRCS = $(BONUS_DIR)checker.c \
            $(BONUS_DIR)free_2d.c \
            $(BONUS_DIR)ft_atoi.c \
            $(BONUS_DIR)ft_strcmp.c \
            $(BONUS_DIR)ft_lstadd_back.c \
            $(BONUS_DIR)ft_lstadd_front.c \
            $(BONUS_DIR)ft_lstclear.c \
            $(BONUS_DIR)ft_lstnew.c \
            $(BONUS_DIR)ft_lstsize.c \
            $(BONUS_DIR)ft_split.c \
            $(BONUS_DIR)isdup.c \
		    $(BONUS_DIR)swap.c \
		    $(BONUS_DIR)push.c \
		    $(BONUS_DIR)rotate.c \
		    $(BONUS_DIR)rrotate.c \
            $(BONUS_DIR)other_size.c \
			$(BONUS_DIR)checker_utils.c \
            $(BONUS_DIR)remove_spaces.c \
            $(BONUS_DIR)set_index.c \
            $(BONUS_DIR)small_size.c

GNL_SRCS = $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) -o $(BONUS_NAME)

$(MANDATORY_DIR)%.o: $(MANDATORY_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(GNL_DIR)%.o: $(GNL_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean
