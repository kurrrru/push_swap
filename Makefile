NAME		= push_swap
DEQUE_SRCS	= deque_basic.c deque_access.c deque_push_pop.c deque_rotate.c deque_swap.c
SRCS		= main.c push_swap.c is_valid_string.c compress.c lis.c lower_bound.c is_duplicated.c is_empty_array.c error.c $(DEQUE_SRCS)
OBJS		= $(SRCS:.c=.o)
LIBDIR		= libft
LIB			= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

.DEFAULT_GOAL = all

$(NAME): $(OBJS) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR)/$(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR)

clean:
	make -C $(LIBDIR) fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
